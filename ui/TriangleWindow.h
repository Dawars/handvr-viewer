//
// Created by David Komorowicz on 2018. 04. 01..
//

#ifndef HANDVR_TRIANGLEWINDOW_H
#define HANDVR_TRIANGLEWINDOW_H


#include <QOpenGLShaderProgram>
#include "OpenGLWindow.h"

class TriangleWindow : public OpenGLWindow {
public:
    TriangleWindow();

    void initialize() override;

    void render() override;

private:
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;

    QOpenGLShaderProgram *m_program;
    int m_frame;
};

TriangleWindow::TriangleWindow()
        : m_program(0), m_frame(0) {
}

#endif //HANDVR_TRIANGLEWINDOW_H
