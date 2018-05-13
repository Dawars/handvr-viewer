//
// Created by David Komorowicz on 2018. 04. 08..
//

#ifndef HANDVR_VIEWER_HANDWIDGET_H
#define HANDVR_VIEWER_HANDWIDGET_H

#include <memory>


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShader>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <src/sensor/leapmotion/LeapHandController.h>
#include <QOpenGLDebugLogger>
#include <src/util/LogHandler.h>
#include <src/ui/HandRenderer.h>

class HandWidget : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT


public:
    explicit HandWidget(QWidget *parent = 0);

    ~HandWidget() = default;

    void setModel(std::shared_ptr<LeapHandController> model);

    QMatrix4x4 getProjection() const;
    QMatrix4x4 getView() const;
    QMatrix4x4 getVP() const;

public slots:

    // slots for xyz-rotation slider
    void setXRotation(int angle);

    void setYRotation(int angle);

    void setZRotation(int angle);


signals:

    // signaling rotation from mouse movement
    void xRotationChanged(int angle);

    void yRotationChanged(int angle);

    void zRotationChanged(int angle);


protected:
    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();


private:

    QVector4D color;

    QMatrix4x4 model;
    QMatrix4x4 view;
    QMatrix4x4 projection;
    QMatrix4x4 viewprojection;
    std::shared_ptr<LeapHandController> handController;

    QOpenGLDebugLogger logger;
    LogHandler logHandler;

    std::shared_ptr<HandRenderer> handRenderer;
};


#endif //HANDVR_VIEWER_HANDWIDGET_H
