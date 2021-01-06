#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new Plot();
    this->takeCentralWidget();
    this->setCentralWidget(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}
