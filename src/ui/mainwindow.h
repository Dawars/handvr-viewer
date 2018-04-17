#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/sensor/leapmotion/LeapController.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;


//private slots:
private:
    Ui::MainWindow *ui;

    std::shared_ptr<LeapController> leapController;
};

#endif // MAINWINDOW_H
