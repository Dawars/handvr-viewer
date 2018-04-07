#include "mainwindow.h"
#include <QApplication>
#include <sensor/leapmotion/LeapData.h>
#include "Leap.h"

int main(int argc, char **argv) {
    LeapData leapData;

    //qt
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();
}