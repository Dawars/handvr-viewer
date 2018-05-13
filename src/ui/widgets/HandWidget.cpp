//
// Created by David Komorowicz on 2018. 04. 08..
//

#include "HandWidget.h"
#include <memory>
#include <utility>
#include <QTimer>
#include <QVector3D>
#include <QtWidgets>
#include <src/ui/SkeletonHandRenderer.h>

HandWidget::HandWidget(QWidget *parent)
        :
        QOpenGLWidget(parent),
        color{0, 0, 0, 1},
        model{},
        view{},
        projection{},
        viewprojection{},
        logger{}, logHandler{},
        handRenderer{std::make_shared<SkeletonHandRenderer>(*this)} {

    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));

}

void HandWidget::initializeGL() {
    initializeOpenGLFunctions();
    std::cout << glGetString(GL_VERSION) << std::endl;

    if (logger.initialize()) {// will get destroyed out of scope
        connect(&logger, &QOpenGLDebugLogger::messageLogged, &logHandler, &LogHandler::handleLoggedMessage);
        logger.startLogging();
    } else {
        qDebug() << "Debug logger not enabled";
    }

    handRenderer->initialize();

    glEnable(GL_DEPTH_TEST);
}

void HandWidget::paintGL() {
    //render
    glClearColor(color.x(), color.y(), color.z(), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // update data
    const auto &hands = handController->getHandRepresentation();
    for (const auto &handRep : hands) {
        handRenderer->paint(handRep->handModel);
    }

    GLenum error = glGetError();
    if (error != 0)qDebug() << error;
}

void HandWidget::resizeGL(int width, int height) {

    viewprojection.setToIdentity();
    viewprojection.perspective(60, (float) width / (float) height, 0.01f, 10000);
    viewprojection.lookAt({100, 100, 300}, {0, 100, 0}, {0, 1, 0});

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
    this->handController = model;
}

QMatrix4x4 HandWidget::getProjection() const {
    return projection;
}

QMatrix4x4 HandWidget::getView() const {
    return view;
}

QMatrix4x4 HandWidget::getVP() const {
    return viewprojection;
}