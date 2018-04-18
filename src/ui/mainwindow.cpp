
#include <QtWidgets>
#include <src/sensor/leapmotion/LeapServiceProvider.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"


// Controller??
MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);


    leapController = std::make_shared<LeapHandController>(std::make_shared<LeapServiceProvider>());
    ui->myGLWidget->setModel(leapController);

}

MainWindow::~MainWindow() {
    delete ui;
}

// getHandPosition