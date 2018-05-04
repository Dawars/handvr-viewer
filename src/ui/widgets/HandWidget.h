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

class HandWidget : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT


public:
    explicit HandWidget(QWidget *parent = 0);

    ~HandWidget();

    void setModel(std::shared_ptr<LeapHandController> model);

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
    QMatrix4x4 mvp;
    std::unique_ptr<QOpenGLVertexArrayObject> m_vao_axis;
    std::unique_ptr<QOpenGLBuffer> m_vbo_axis;
    std::unique_ptr<QOpenGLBuffer> m_vbo_color;
    std::unique_ptr<QOpenGLBuffer> m_ibo;
    std::unique_ptr<QOpenGLShaderProgram> axisShader;
    std::unique_ptr<QOpenGLTexture> m_texture;
    std::shared_ptr<LeapHandController> handController;

    QOpenGLDebugLogger logger;
    LogHandler logHandler;

//    std::shared_ptr<RenderHands> handRenderer;
};


#endif //HANDVR_VIEWER_HANDWIDGET_H
