#ifndef QMESSAGE_REMIND_H
#define QMESSAGE_REMIND_H
#include<QMessageBox>
#include<QTimer>
//改为单例模式
//单例提醒窗口
class message_remind{
public:
    inline ~message_remind(){delete box;}
    message_remind(const message_remind& m) =delete;//禁止拷贝构造
    message_remind& operator=(const message_remind& m)=delete;//禁止拷贝赋值
    void show(const QString& s,const QString& title = "",uint time = 2)const {
        box->setText(s);
        QTimer::singleShot(time*1000,box,SLOT(close()));
        box->show();
    }
    void close()const {
        box->close();
    }
    static message_remind* get_Mremind() {
        if (General_Box == nullptr) {
            General_Box = new message_remind("total");
        }
        return General_Box;
    }

protected:
    QMessageBox *box;
    static message_remind* General_Box;
private:
    inline message_remind(const QString& title){box = new QMessageBox(QMessageBox::NoIcon,title,"",nullptr,nullptr);}
};
#endif // QMESSAGE_REMIND_H
