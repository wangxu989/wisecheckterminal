#include "startwork.h"
#include "ui_startwork.h"
#include<QDebug>
startwork::startwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startwork)
{
    ui->setupUi(this);
    layout_tool::bfs_tool(this->QWidget::layout(),[&](QWidget*w){
        if(dynamic_cast<MyLEdit*>(w) != nullptr) {
            qDebug()<<"OK";
            MyLEdit* e =  dynamic_cast<MyLEdit*>(w);
            // e->setText("111");
            int r,g,b;
            e->palette().background().color().getRgb(&r,&g,&b);
            qDebug()<<r<<" "<<g<<" "<<b;
            if(r == 241 && g == 97 && b == 97) {
                start_need_warn.push_back(e);
            }
        }

    });
}

startwork::~startwork()
{
    delete ui;
}
void startwork::insert_YG(const QString& s) {
    ui->lineEdit->setText(s);
}
void startwork::insert_YG_N(const QString &s) {
    ui->lineEdit_10->setText(s);
}

void startwork::insert_SB(const QString& s) {
    ui->lineEdit_2->setText(s);
}
void startwork::insert_SB_N(const QString &s) {
    ui->lineEdit_11->setText(s);
}
void startwork::insert_SB_Department(const QString &s) {
    ui->lineEdit_13->setText(s);
}

void startwork::insert_ZL(const QString& s) {
    ui->lineEdit_3->setText(s);
}
void startwork::insert_Elf(const QString& s) {
    ui->lineEdit_4->setText(s);
}
void startwork::insert_MustQC(const QString& s) {
    ui->lineEdit_5->setText(s);
}
void startwork::insert_Box(const QString& s) {
    ui->lineEdit_6->setText(s);
}
