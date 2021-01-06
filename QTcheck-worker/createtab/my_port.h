#ifndef MY_PORT_H
#define MY_PORT_H
#include<QSerialPort>
#include<QDebug>
#include<QSerialPortInfo>
#include<QTableWidget>
#include<QHeaderView>
#include<QSemaphore>
#include<socketclient.h>
#include<QtXml/QDomDocument>
#include<QFile>
#include<QMessageBox>
#include<qmessage_remind.h>
#include<my_shared_ptr.h>
//重构为单例

/*des: 为了实现即用即构造的单例模式（不用时能析构的单例），采用shared_ptr。为了能让单例模式将所有权转让给其他模块（即通过单例模式构造不增加引用计数）
自己实现了my_shared_ptr实现0引用计数构造，详见my_shared_ptr.h */

struct Device{
    QString name;
    QString baudRate;
    QString dataBits;
    QString stopBits;
    QString parity;
    QString writeBufferSize;
    QString readBufferSize;
};

class my_port:public QObject
{
    Q_OBJECT
public:
    ~my_port();
    void write(const QString& s);
    static my_shared_ptr<my_port> get_myport() {
        if (p.empty()) {
            qDebug()<<"single_port";
            my_port *t = new my_port();
            p = std::move(my_shared_ptr<my_port>(t,0));
            qDebug()<<"now_cnt    "<<p.get_cnt();
        }
        return p;
    }
    static my_shared_ptr<my_port> p;

protected:
    my_port();
private:
    enum Except{
        WRITE,
        READ
    };
    QSharedPointer<QSerialPort> port_print,port_scan;//printer/scanner
    void lookup(void);
    void start_port();
    //QString name;
    QSerialPortInfo my_info_printer,my_info_scanner;
    Device scanner,printer;
    bool exception(const Except& e);
    bool find_port();
    message_remind* Mremind = message_remind::get_Mremind();
};

#endif // MY_PORT_H
