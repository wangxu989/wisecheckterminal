#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<plot.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Plot* p;
};

#endif // MAINWINDOW_H
