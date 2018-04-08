#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../sensor/leapmotion/LeapData.h"

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

};

#endif // MAINWINDOW_H
