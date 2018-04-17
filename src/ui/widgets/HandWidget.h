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
#include <src/sensor/leapmotion/LeapController.h>
#include <QOpenGLDebugLogger>
#include <src/util/LogHandler.h>

class HandWidget : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT


public:
    explicit HandWidget(QWidget *parent = 0);

    ~HandWidget();

    void setModel(std::shared_ptr<LeapController> model);

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
    std::unique_ptr<QOpenGLVertexArrayObject> m_vao;
    std::unique_ptr<QOpenGLBuffer> m_vbo;
    std::unique_ptr<QOpenGLBuffer> m_ibo;
    std::unique_ptr<QOpenGLShaderProgram> m_program;
    std::unique_ptr<QOpenGLTexture> m_texture;
    std::shared_ptr<LeapController> model;

    QOpenGLDebugLogger logger;
    LogHandler logHandler;

};


#endif //HANDVR_VIEWER_HANDWIDGET_H
