#include "my_port.h"
#include<QTime>
#include<QThread>
#include<sys/stat.h>
my_shared_ptr<my_port> my_port::p = my_shared_ptr<my_port>(nullptr);
template<>bool  my_shared_ptr<my_port>::status = true;
my_port::my_port():port_print(nullptr),port_scan(nullptr)
{
    lookup();
    //start_port();
}
my_port::~my_port() {
    qDebug()<<"delete my_port";
    //p.data() = NULL;
}
bool my_port::exception(const Except &e) {
    switch(e) {
        case WRITE:
        if(port_print.data() == nullptr) {
            qDebug()<<"not open printer port";
            port_print = QSharedPointer<QSerialPort>(new QSerialPort());
        }
        if (!port_print->isOpen()) {
            qDebug()<<"not open printer port";
            port_print->setPort(my_info_printer);
            if(!port_print->open(QIODevice::ReadWrite)) {
                Mremind->show("open printer port failed");
                return false;
            }
        }
        return true;
        break;
        default:
        Mremind->show("invaild type of Exception");
        return false;
    }
}

void my_port::write(const QString &s) {
//处理异常
    if(exception(WRITE)) {
        port_print->write(s.toUtf8());
    }
}

void my_port::lookup() {
    //first readxml
    QFile file("./data/GeneralConfig.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox box(QMessageBox::NoIcon,"config","open GeneralConfig.xml failed!",NULL,NULL);
        return;
    }
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        file.close();
        QMessageBox messageBox;
        messageBox.setText("read GeneralConfig.xml failed !");
        messageBox.exec();
        return ;
    }
    file.close();
    QDomElement domele = doc.documentElement();
    QDomNode n = domele.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement();
        QDomNodeList list = e.childNodes();
        if (e.tagName() == "SerialPorts") {
            for(int i = 0;i < list.size();i++){
                QDomNode node = list.at(i);
                QDomElement E_temp = node.toElement();
                if (E_temp.attribute("device") == "Printer") {
                    printer.name = E_temp.attribute("portName");
                    printer.baudRate = E_temp.attribute("baudRate");
                    printer.dataBits = E_temp.attribute("dataBits");
                    printer.stopBits = E_temp.attribute("stopBits");
                    printer.parity = E_temp.attribute("parity");
                    printer.writeBufferSize = E_temp.attribute("writeBufferSize");
                    printer.readBufferSize = E_temp.attribute("readBufferSize");
                    qDebug()<<printer.name<<"   printer_name";
                }
                else if (E_temp.attribute("device") == "Scanner") {
                    scanner.name = E_temp.attribute("portName");
                    scanner.baudRate = E_temp.attribute("baudRate");
                    scanner.dataBits = E_temp.attribute("dataBits");
                    scanner.stopBits = E_temp.attribute("stopBits");
                    scanner.parity = E_temp.attribute("parity");
                    scanner.writeBufferSize = E_temp.attribute("writeBufferSize");
                    scanner.readBufferSize = E_temp.attribute("readBufferSize");
                    qDebug()<<scanner.name<<"    scanner_name";
                }

            }
        }
        n = n.nextSibling();

    }
    find_port();
}
void my_port::start_port(){
    port_print = QSharedPointer<QSerialPort>(new QSerialPort());
    if (port_print->isOpen()) {
        port_print->clear();
        port_print->close();
    }
    port_scan =  QSharedPointer<QSerialPort>(new QSerialPort());
    if (port_scan->isOpen()) {
        port_scan->clear();
        port_scan->close();
    }
    port_print->setPort(my_info_printer);
    port_scan->setPort(my_info_scanner);
    if (!port_print->open(QIODevice::ReadWrite)) {
        qDebug()<<port_print->errorString();
        qDebug()<<"open port failed";
        //exit(0);
    }
    port_print->setBaudRate(QSerialPort::Baud9600);//设置波特率和读写方向
    port_print->setDataBits(QSerialPort::Data8);		//数据位为8位
    port_print->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    port_print->setParity(QSerialPort::NoParity);	//无校验位
    port_print->setStopBits(QSerialPort::OneStop); //一位停止位
    if (!port_scan->open(QIODevice::ReadWrite)) {
        qDebug()<<port_print->errorString();
        qDebug()<<"open port failed";
        //exit(0);
    }
    port_scan->setBaudRate(QSerialPort::Baud9600);//设置波特率和读写方向
    port_scan->setDataBits(QSerialPort::Data8);		//数据位为8位
    port_scan->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    port_scan->setParity(QSerialPort::NoParity);	//无校验位
    port_scan->setStopBits(QSerialPort::OneStop); //一位停止位
}
bool my_port::find_port() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {

        if (info.portName() == printer.name) {//info.serialNumber() == "A7434VMK"
            qDebug() << "Name : " << info.portName();
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();
            qDebug() << "Serial Number: " << info.serialNumber();
            qDebug() << "System Location: " << info.systemLocation();
            my_info_printer = info;
            //return true;
        }
        else if (info.portName() == scanner.name) {
            my_info_scanner = info;
        }

    }
    return false;
}
