//
// Created by David Komorowicz on 2018. 04. 01..
//

#ifndef HANDVR_OPENGLWINDOW_H
#define HANDVR_OPENGLWINDOW_H


#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>

class OpenGLWindow : public QWindow, protected QOpenGLFunctions {
Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);

    ~OpenGLWindow();

    virtual void render(QPainter *painter);

    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

public slots:

    void renderLater();

    void renderNow();

protected:
    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif //HANDVR_OPENGLWINDOW_H
