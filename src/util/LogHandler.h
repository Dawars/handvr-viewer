//
// Created by David Komorowicz on 2018. 04. 15..
//

#ifndef HANDVR_VIEWER_LOGHANDLER_H
#define HANDVR_VIEWER_LOGHANDLER_H


#include <QObject>
#include <QOpenGLDebugMessage>

class LogHandler : public QObject {
Q_OBJECT

public slots:
    void handleLoggedMessage(const QOpenGLDebugMessage &debugMessage);

};


#endif //HANDVR_VIEWER_LOGHANDLER_H
