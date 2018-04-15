//
// Created by David Komorowicz on 2018. 04. 15..
//

#include <iostream>
#include "LogHandler.h"

void LogHandler::handleLoggedMessage(const QOpenGLDebugMessage &debugMessage) {
    qDebug() << debugMessage;
}
