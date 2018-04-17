
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"


// Controller??
MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);


    leapController = std::make_shared<LeapController>();
    ui->myGLWidget->setModel(leapController);

}

MainWindow::~MainWindow() {
    delete ui;
}

// getHandPosition