#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H
#include<tab.h>
#include<QVBoxLayout>
class keyboard_table:public my_tablewidget{
public:
    keyboard_table(const QString&s ,int row = 4,int column = 4):my_tablewidget(row,column) {
        QFont ft;//字体大小
        ft.setPointSize(24);
        this->setSpan(0,3,2,1);
        this->setSpan(2,3,2,1);
        this->setSpan(3,0,1,2);
        this->item(3,2)->setText(".");
        this->item(2,3)->setText(s);
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                this->item(i,j)->setText(QString::number(7 - i*3 + j));
            }
        }
        t_label = QSharedPointer<QLabel>(new QLabel());
        t_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        t_label->setPixmap(QPixmap(":/new/prefix1/img/cancel.png"));
        this->setCellWidget(0,3,t_label.data());
        this->item(3,0)->setText("0");
        this->setFont(ft);
    }

private:
    enum status{
        Normal,

    };
//    ~keyboard_table() {
//        delete t_label;
//    }

private:
     QSharedPointer<QLabel> t_label;
     QSharedPointer<QVBoxLayout>layout;
};

#endif // KEYBOARD_BASE_H
