#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/sensor/leapmotion/LeapHandController.h"

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

    std::shared_ptr<LeapHandController> leapController;
};

#endif // MAINWINDOW_H
