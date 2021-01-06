#ifndef FINISH_WORK_H
#define FINISH_WORK_H
#include<QThread>
#include <QWidget>
#include<QHBoxLayout>
#include<myledit.h>
#include<QDateTime>
#include<QLocale>
#include<qmessage_remind.h>
#include<database.h>
#include<keyboard_base.h>
#include<my_tablewidget.h>
#include<myledit.h>
#include<my_layout.h>
#include<my_layout.h>
//子功能3完工信息页面
class waitfordeal_type{
public:
    QString id;
    QString type;
    QString cnt = "0";
    QString& operator[](int n) {
        return *((QString*)this + n);
    }
};


namespace Ui{
class finish_work;
}
class my_time{
public:
    static my_time* get_time() {
        if (time == nullptr) {
            time = new my_time();
        }
        return time;
    }
    ~my_time() {
        delete time;
    }
    QString get_currenttime(int time_scope = 0) {
        QDateTime dateTime = QDateTime::fromTime_t(QDateTime::currentDateTime().toTime_t() - time_scope*24*3600);
        QLocale locale1;//指定英文显示
        QString strFormat = "yyyy-MM-dd hh:mm:ss";
        //return std::move(locale1.toString(dateTime, strFormat));
        return locale1.toString(dateTime, strFormat);
    }
    QString get_time_format1(int time_scope = 0,QDateTime t = QDateTime::currentDateTime()) {
        QDateTime time = QDateTime::fromTime_t(t.toTime_t() - time_scope*24*3600);
        QString cmp_end = (time.date().year() - 2000 < 10 ? "0":"") +  QString::number(time.date().year() - 2000) +
                      (time.date().month() < 10 ? "0":"") +  QString::number(time.date().month()) +
                      (time.date().day() < 10 ? "0":"") +  QString::number(time.date().day())+
                      (time.time().hour() < 10 ? "0":"") + QString::number(time.time().hour()) +
                      (time.time().minute() < 10 ? "0":"") + QString::number(time.time().minute()) +
                      (time.time().second() < 10 ? "0":"") + QString::number(time.time().second());
        return cmp_end;
    }

protected:
    static my_time* time;
    my_time(){}
private:

};

namespace Program3 {

class time_update:public QThread{
    Q_OBJECT
public:
    time_update(MyLEdit *line):my_line(line) {
        time = my_time::get_time();
        start();
    }
    void run() {
        while(!stop) {
            sleep(1);
            my_line->setText(time->get_currenttime());
        }
    }
    ~time_update() {
        stop = true;
        wait();
    }

private:
    volatile bool stop = false;
    MyLEdit* my_line;
    my_time* time;
};

class finish_work : public QWidget
{
    Q_OBJECT
    //friend time_update;
public:
    explicit finish_work(QWidget *parent = 0);
    ~finish_work();
//    QHBoxLayout* get_layout() {
//        return layout.data();
//    }
    bool setText(const QString&);
    QString text()const;
    QString getEndCount();
    QString getCurrentTime();
    QString get_Finish_Count();
    QString get_Probatch();
    QString get_s10();
    QString get_s11();
    QString get_s12();
    QString get_sElesIf();
    QString get_s16();
    QString get_worktime();
    bool check();
    bool check_s16();
    void init(const QString& s);
    bool GetBoxIndex(int& nPlanCappIndex, int& nBatchCappIndex,const QString& ID);
    QString Qrencode;
    QString starttime;
    int nPlanCappIndex,nBatchCappIndex;
    QString processname;
    QString get_residueNum();
    void insert_YG(const QString& s);
    void insert_YG_N(const QString& s);
    void insert_SB(const QString& s);
    void insert_SB_N(const QString& s);
    void insert_SB_Department(const QString& s);
    void insert_ZL(const QString& s);
    void insert_Elf(const QString& s);
    void insert_Probatch(const QString& s);
    void insert_IR(const QString& s);
    void insert_waitfordeal(const QString& s);
    QString get_waitfordeal_string() {
        return end_string;
    }
    void set_finishtime(const QString&s);

private:
    enum keyboard_status{//键盘输入模式，正常、弹出
        Normal,
        WaitForDeal
    };
    int keyboard_model = Normal;
    void hide();//非填写内容
    void unhide();
    void hide_write();//填写内容
    void unhide_write();
    void call_keyboard();
    QSharedPointer<QHBoxLayout>layout;
    Ui::finish_work *ui;

    void ret_keyboard();
    void ret_keyboard_waitfordeal();

    MyLEdit* now;
    QSharedPointer<time_update>last_time;
    message_remind* Mremind = message_remind::get_Mremind();
    socket* my_socket = socket::get_socket();
    QString CmdID;
    QSharedPointer<keyboard_table>keyboard;
    QVBoxLayout *waitfordeal;
    layout_base layout_deal;
    QFrame *wfd;
    QPushButton* enter = nullptr;
    QString on_hand;
    QString end_string;
    QVector<MyLEdit*>finish_need_warn;
//    using keyboard_exec =  decltype(ret_keyboard);
//    keyboard_exec key_exec;
public slots:
    QString on_pushButton_2_clicked();
private slots:
    void label_change(MyLEdit*);
    void on_pushButton_clicked();
    void in_keyboard(int row, int column);
signals:
    void invoke_keyboard();
};
}

#endif // FINISH_WORK_H
