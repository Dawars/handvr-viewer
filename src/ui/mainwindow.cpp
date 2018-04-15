
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"


// Controller??
MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);


    model = std::make_shared<LeapData>();
    ui->myGLWidget->setModel(model);

}

MainWindow::~MainWindow() {
    delete ui;
}

// getHandPosition