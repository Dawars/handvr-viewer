//
// Created by David Komorowicz on 2018. 04. 08..
//

#include "HandWidget.h"
#include <memory>
#include <utility>
#include <QTimer>

HandWidget::HandWidget(QWidget *parent) : QOpenGLWidget(parent),
                                          color{1, 0, 1, 1},
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
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,

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
        m_vbo->allocate(positions, 4 * 2 * sizeof(float));
        m_vbo->setUsagePattern(QOpenGLBuffer::UsagePattern::StaticDraw);


        m_program->setAttributeBuffer("position", GL_FLOAT, 0, 2, 2 * sizeof(float));
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

    m_vao->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);


}

void HandWidget::resizeGL(int width, int height) {
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
    this->model = model;
}
