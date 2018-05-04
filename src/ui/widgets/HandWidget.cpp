//
// Created by David Komorowicz on 2018. 04. 08..
//

#include "HandWidget.h"
#include <memory>
#include <utility>
#include <QTimer>
#include <QVector3D>
#include <QtWidgets>

HandWidget::HandWidget(QWidget *parent)
        :

        QOpenGLWidget(parent),
        color{1, 0, 1, 1},
        model{},
        view{},
        projection{},
        logger{}, logHandler{} {

    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));

}

HandWidget::~HandWidget() {
// Make sure the context is current and then explicitly
    // destroy all underlying OpenGL res.
    makeCurrent();


//    m_vbo_axis->destroy();
//    m_ibo->destroy();
//    m_vao_axis->destroy();

    doneCurrent();
}

struct Vertex {
    QVector3D position;
    QVector3D color;
};

Vertex axis[] = {
        {QVector3D(0, 0, 0),  QVector3D(1, 0, 0)},
        {QVector3D(10, 0, 0), QVector3D(1, 0, 0)},
        {QVector3D(0, 0, 0),  QVector3D(0, 1, 0)},
        {QVector3D(0, 10, 0), QVector3D(0, 1, 0)},
        {QVector3D(0, 0, 0),  QVector3D(0, 0, 1)},
        {QVector3D(0, 0, 10), QVector3D(0, 0, 1)},
};


void HandWidget::initializeGL() {
    initializeOpenGLFunctions();
    std::cout << glGetString(GL_VERSION) << std::endl;

    if (logger.initialize()) {// will get destroyed out of scope
        connect(&logger, &QOpenGLDebugLogger::messageLogged, &logHandler, &LogHandler::handleLoggedMessage);
        logger.startLogging();
    } else {
        qDebug() << "Debug logger not enabled";
    }


    m_vao_axis = std::make_unique<QOpenGLVertexArrayObject>();
    m_vbo_axis = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
    m_ibo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::IndexBuffer);

    axisShader = std::make_unique<QOpenGLShaderProgram>();
    axisShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Axis.vert");
    axisShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Axis.frag");
    axisShader->link();

    m_vao_axis->create();
    if (m_vao_axis->isCreated())
        m_vao_axis->bind();

    if (m_vbo_axis->create()) {
        m_vbo_axis->bind();
        m_vbo_axis->allocate(axis, 6 * sizeof(Vertex));
        m_vbo_axis->setUsagePattern(QOpenGLBuffer::UsagePattern::StaticDraw);


        axisShader->setAttributeBuffer("position", GL_FLOAT, offsetof(Vertex, position), 3, sizeof(Vertex));
        axisShader->enableAttributeArray(0);
        axisShader->setAttributeBuffer("color", GL_FLOAT, offsetof(Vertex, color), 3, sizeof(Vertex));
        axisShader->enableAttributeArray(1);


        m_vbo_axis.release();
        m_vbo_color.release();
    }
//    handRenderer = std::make_shared<RenderHands>(this, *handController);

    glEnable(GL_DEPTH_TEST);
}

void HandWidget::paintGL() {
    //render
    glClearColor(0.55f, 0.55f, 0.55f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    axisShader->bind();
    axisShader->setUniformValue("transform", mvp);
// coordinate system center
    m_vao_axis->bind();
    glDrawArrays(GL_LINES, 0, 6);

    // update data
    const auto &hands = handController->getHandRepresentation();
    for (const auto &handRep : hands) {
        const auto &hand = handRep->handModels[0]->GetLeapHand();

        const Leap::Vector &handPos = hand->palmPosition();
        model.setToIdentity();
        model.translate(handPos.x, handPos.y, handPos.z);

        /* for (auto &finger: hand->fingers()) {
             for (int i = 0; i <= Leap::Bone::Type::TYPE_DISTAL; ++i) {
                 int fingerId = finger.type();

                 const Leap::Bone &bone = finger.bone(static_cast<Leap::Bone::Type>(i));

                 const Leap::Vector &pos = bone.prevJoint();

                 int id = 1 + 5 * fingerId + i;
                 positions[3 * id + 0] = pos.x;
                 positions[3 * id + 1] = pos.y;
                 positions[3 * id + 2] = pos.z;

             }
         }*/

    // rendering hand center
    const QMatrix4x4 &handMat = mvp * model;
    axisShader->setUniformValue("transform", handMat);

    m_vao_axis->bind();
    glDrawArrays(GL_LINES, 0, 6);


}
//    handRenderer->render();

    GLenum error = glGetError();
    if (error != 0)qDebug() << error;
}

void HandWidget::resizeGL(int width, int height) {

    mvp.setToIdentity();
    mvp.perspective(60, (float) width / (float) height, 0.01f, 10000);
    mvp.lookAt({100, 100, 300}, {0, 100, 0}, {0, 1, 0});
    mvp.translate(0, 0, 0);
    qDebug() << mvp;

    // Adjust the viewport based on geometry changes,
    // such as screen rotation
    glViewport(0, 0, width, height);
}

void HandWidget::setXRotation(int angle) {
    color.setX(angle / 255.f);
    repaint();
}

void HandWidget::setYRotation(int angle) {
    color.setY(angle / 255.f);
    repaint();

}

void HandWidget::setZRotation(int angle) {
    color.setZ(angle / 255.f);
    repaint();

}

void HandWidget::setModel(std::shared_ptr <LeapHandController> model) {
    this->handController = model;
}
