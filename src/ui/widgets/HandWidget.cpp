//
// Created by David Komorowicz on 2018. 04. 08..
//

#include "HandWidget.h"
#include <memory>
#include <utility>
#include <QTimer>
#include <QVector3D>
#include <QtWidgets>

HandWidget::HandWidget(QWidget * parent)
:

QOpenGLWidget (parent),
color{1, 0, 1, 1},
model{},
view{},
projection{},
logger{}, logHandler{} {


}

HandWidget::~HandWidget() {
// Make sure the context is current and then explicitly
    // destroy all underlying OpenGL res.
    makeCurrent();


//    m_vbo->destroy();
//    m_ibo->destroy();
//    m_vao->destroy();

    doneCurrent();
}

float positions[] = {
        -100, -100, 0,
        100, -100, 0,
        100, 100, 0,
        -100, 100, 0

};
unsigned short indices[] = {
        0, 1, 2,
        2, 3, 0
};

void HandWidget::initializeGL() {
    initializeOpenGLFunctions();
    std::cout << glGetString(GL_VERSION) << std::endl;

    /*if (logger.initialize()) {// will get destroyed out of scope
        connect(&logger, &QOpenGLDebugLogger::messageLogged, &logHandler, &LogHandler::handleLoggedMessage);
        logger.startLogging();
    } else {
        qDebug() << "Debug logger not enabled";
    }*/


    m_vao = std::make_unique<QOpenGLVertexArrayObject>();
    m_vbo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
    m_ibo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::IndexBuffer);

//    m_shader = new QOpenGLShader(QOpenGLShader::ShaderTypeBit::Vertex);
//    m_shader->compileSourceFile();
    m_program = std::make_unique<QOpenGLShaderProgram>();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Common.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Common.frag");
    m_program->link();

    m_vao->create();
    if (m_vao->isCreated())
        m_vao->bind();

    if (m_vbo->create()) {
        m_vbo->bind();
        m_vbo->allocate(positions, 4 * 3 * sizeof(float));
        m_vbo->setUsagePattern(QOpenGLBuffer::UsagePattern::StaticDraw);


        m_program->setAttributeBuffer("position", GL_FLOAT, 0, 3, 3 * sizeof(float));
        m_program->enableAttributeArray(0);


        m_ibo->create();
        m_ibo->bind();
        m_ibo->allocate(indices, 6 * sizeof(unsigned short));
        m_ibo->setUsagePattern(QOpenGLBuffer::UsagePattern::StaticDraw);

        m_vbo.release();
    }
    //    m_texture = new QOpenGLTexture(QImage(...));

//    QOpenGLDebugMessage()
    // axis vert array

}

void HandWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();
    m_program->setUniformValue("u_Color", color);
    m_program->setUniformValue("transform", mvp);
    qDebug() << glGetError();

    m_vao->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);


}

QMatrix4x4 lookAt(QVector3D eye, QVector3D center, QVector3D up) {
    QVector3D direction = (eye - center).normalized();
    QVector4D right = QVector3D::crossProduct(up, direction).normalized();

    QMatrix4x4 view = {
            right.x(), right.y(), right.z(), 0,
            up.x(), up.y(), up.z(), 0,
            direction.x(), direction.y(), direction.z(), 0,
            0, 0, 0, 1
    };
    view.translate(-eye.x(), -eye.y(), -eye.z());
    return view;
}

QMatrix4x4 getProjectionMatrix(float fovy, float aspect, float near, float far) {
    float top = tan(fovy / 2) * near;
    float bottom = -top;
    float right = aspect * top;
    float left = -right;

    QMatrix4x4 proj = {
            (2 * near) / (right - left), 0, (right + left) / (right - left), 0,
            0, -(2 * near) / (top - bottom), (top + bottom) / (top - bottom), 0,
            0, 0, -(far + near) / (far - near), -(2 * far * near) / (far - near),
            0, 0, -1, 0
    };
    return proj;
}

void HandWidget::resizeGL(int width, int height) {

    mvp.setToIdentity();
    mvp.perspective(60, (float) width / (float) height, 0.01f, 10000);
    mvp.lookAt({0, 0, 300}, {0, 0, 0}, {0, 1, 0});
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

void HandWidget::setModel(std::shared_ptr<LeapHandController> model) {
    this->handModel = model;
}
