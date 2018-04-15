#include "ui/mainwindow.h"
#include <QApplication>
#include "sensor/leapmotion/LeapData.h"
#include <Leap.h>
#include <QSurfaceFormat>

int main(int argc, char **argv) {

    //qt
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setOption(QSurfaceFormat::DebugContext);
    format.setSamples(4);
    format.setSwapInterval(1);

    QSurfaceFormat::setDefaultFormat(format);

    MainWindow w;
    w.show();

    return app.exec();
}