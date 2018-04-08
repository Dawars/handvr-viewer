#include "ui/mainwindow.h"
#include <QApplication>
#include "sensor/leapmotion/LeapData.h"
#include <Leap.h>

int main(int argc, char **argv) {

    //qt
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

//    LeapData leapData{&w};

    return app.exec();
}