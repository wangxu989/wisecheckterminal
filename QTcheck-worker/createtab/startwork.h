#ifndef STARTWORK_H
#define STARTWORK_H

#include <QWidget>
#include<myledit.h>
#include<my_layout.h>

namespace Ui {
class startwork;
}
class startwork : public QWidget
{
    Q_OBJECT

public:
    explicit startwork(QWidget *parent = 0);
    ~startwork();
    QString text(){
        return QString();
    }
    bool setText(const QString& s) {
        return true;
    }
    void setStyleSheet(const QString&s){
    }
    void setFont(QFont f) {

    }
    void insert_YG(const QString& s);
    void insert_YG_N(const QString& s);
    void insert_SB(const QString& s);
    void insert_SB_N(const QString&s);
    void insert_SB_Department(const QString&s);
    void insert_ZL(const QString& s);
    void insert_Elf(const QString& s);
    void insert_MustQC(const QString& s);
    void insert_Box(const QString& s);

private:
    Ui::startwork *ui;
    QVector<MyLEdit*>start_need_warn;
};

#endif // STARTWORK_H
