//
// Created by David Komorowicz on 2018. 04. 08..
//

#ifndef HANDVR_VIEWER_HANDWIDGET_H
#define HANDVR_VIEWER_HANDWIDGET_H


#include <QOpenGLWidget>

class HandWidget : public QOpenGLWidget {
Q_OBJECT
public:
    explicit HandWidget(QWidget *parent = 0);

    ~HandWidget();

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

};


#endif //HANDVR_VIEWER_HANDWIDGET_H
