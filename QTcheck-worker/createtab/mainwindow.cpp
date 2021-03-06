#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QImage>
#include<QtXml/QDomDocument>
#include<QFile>
#include<QMessageBox>
#include<QDebug>
#include<QPushButton>
//登录界面
int mode;//网络版还是单机版
message_remind* message_remind::General_Box = nullptr;
QSharedPointer<QMap<QString,baseP*>> baseP::allP = QSharedPointer<QMap<QString,baseP*>>(nullptr);
socket* socket::my_socket = nullptr;
int my_button::num = 0;


database_server *data_server = NULL;//数据库类
database_local *data_local = NULL;
QMap<QString,serialport_info>Serial_port;//串口信息
database_plugin net_plugin;//网络配置
using app_info =  QPair<QString,QString>;
QVector<app_info>app_name;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint); // 去掉标题栏,去掉任务栏显示，窗口置顶
    ui->setupUi(this);
    mode = read_generalxml();
    if (mode == 1) {
        qDebug()<<"网络版";
        data_server = new database_server(net_plugin);
        if (data_server->flag > 0) {
            //0员工信息不合法,1您无权访问此机器,2无对应工作信息
            return;
        }
    }
    data_local = new database_local();//保留本地工作信息
    baseP::p_init();//初始化主程序（父类）
    V_layout1 = new QGridLayout();
//    V_layout2 = new QGridLayout();
//    H_layout = new QGridLayout();
    main_widget = new QWidget();
    main_widget->setLayout(V_layout1);
    this->setStyleSheet("QWidget#MainWindow{border-image: url(:/new/prefix1/img/bj.jpg);}");
    //my_button::init_num();//初始化按钮个数
    draw_init();
    //main_widget->setStyleSheet("QWidget{border-image: url(:/new/prefix1/img/bj.jpg);}");
    this->takeCentralWidget();
    this->setCentralWidget(main_widget);
    this->show();
}

MainWindow::~MainWindow()
{
    QMap<QString,baseP*>::iterator iter = baseP::allP.data()->begin();
    for (;iter != baseP::allP.data()->end();iter++) {
        iter.value()->finish_P();
    }
    delete V_layout1;
    //delete V_layout2;
    //delete H_layout;
    for (auto& a:app_button) {
        if (a != nullptr){
            delete a;
        }
    }
    delete ui;
}
void MainWindow::draw_init() {
    int i = 0;
    //为按钮动态绑定点击槽函数
    QLabel *desc_head = new  QLabel();
    QFont font;
    font.setPointSize(30);
    desc_head->setFont(font);
    desc_head->setAlignment( Qt::AlignHCenter);
    desc_head->setText("生产现场采集客户端软件");
    //desc_head->setEnabled(false);
    V_layout1->addWidget(desc_head,0,0,1,4);
    for (;i < app_button.size();i++) {//暂时将按钮分为2行
        int width_size = main_widget->size().width();
        app_button[i]->setFixedSize(width_size/2,240);

         V_layout1->addWidget(app_button[i],i%2 + 1,i/2 + 1);
        //app_button[i]->setStyleSheet("QPushButton{font-family:'宋体';font-size:32px;color:rgb(0,0,0,255);}\
                                     QPushButton{background-color:rgb(170,200,50)}\
                                     QPushButton:hover{background-color:rgb(50, 170, 200)}");
        connect(app_button[i],&my_button::clicked,this,[&,i]()->bool{emit ctl(i);});
    }
    font.setPointSize(15);
    QLabel *desc = new QLabel();
    desc->setFont(font);
    desc->setAlignment( Qt::AlignHCenter);
    desc->setText("版权所有:南京康尼精密机械有限公司");
    V_layout1->addWidget(desc,4,0,-1,4);
    app_button[0]->setStyleSheet("");

    //app_button[0]->setIconSize(app_button[0]);
    app_button[0]->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/img/spc.jpg);}");
    app_button[0]->setText("");
    app_button[2]->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/img/4.jpg);}");
    app_button[2]->setText("");
    app_button[3]->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/img/3.jpg);}");
    app_button[3]->setText("");
    app_button[1]->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/img/2.png);}");
    app_button[1]->setText("");
//    H_layout->addChildLayout(V_layout1);
//    H_layout->addChildLayout(V_layout2);
    connect(this,&MainWindow::ctl,this,[&](int i)->void{
        abstract_factory* factory;
        qDebug()<<i;
        switch(i) {
        case 0:
            if (mode == 1 && !data_server->isActive()) {
                return ;
            }
            factory = new factory_ProgramWork();//第一个子功能，工作记录
            break;
        case 1:
            if (mode != 1 || !data_server->isActive()) {
                //QMessageBox box(QMessageBox::NoIcon,"network","非网络模式无法使用",NULL,NULL);
                //box.exec();
                return;
            }
            factory = new factory_program2();
            break;
        case 2:
            if (mode != 1 || !data_server->isActive()) {
                //Mremind->show("非网络模式无法使用");
                return;
            }
            factory = new factory_start_finish_work();
            break;
        case 3:
            factory = new factory_analysis();
            break;
        }
        BaseP = factory->Concrete(app_name[i].second.split(" ")[0]);
        connect(BaseP->get_widget(),&MyWidget::change_widget,this,&MainWindow::change_widget);
        if (BaseP->start_P()) {
            this->takeCentralWidget();
            this->setCentralWidget(BaseP->get_widget());
        }
        else {
            qDebug()<<"start failed";
        }

    });

}
void MainWindow::change_widget(QWidget* w) {
    //qDebug()<<"change_widget"<<n;
    takeCentralWidget();
    if (w == nullptr) {
        setCentralWidget(main_widget);
        delete BaseP;
    }
    else {
        setCentralWidget(w);
    }
}

int MainWindow::read_generalxml(){
    QFile file("./data/GeneralConfig.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox messageBox;
        messageBox.setText("open ./GeneralConfig.xml failed !");
        messageBox.exec();
        return -1;
    }
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        file.close();
        QMessageBox messageBox;
        messageBox.setText("read GeneralConfig.xml failed !");
        messageBox.exec();
        return -1;
    }
    file.close();
    QDomElement domele = doc.documentElement();
    QDomNode n = domele.firstChild();
    while (!n.isNull()) {
        if (n.isElement()) {
            QDomElement e = n.toElement();
            if (e.tagName() == "WorkMode") {
                net_plugin.status = e.attribute("mode");
            }
            else if (e.tagName() == "DatabaseConnect") {
                QDomNodeList list = e.childNodes();
                qDebug()<<list.count()<<"databaseconnect";
                for (int i = 0;i < list.count();i++) {
                    if (list.at(i).toElement().tagName() == "RemoteDatabase") {
                        net_plugin.hostname = list.at(i).toElement().attribute("hostName");
                        net_plugin.port = list.at(i).toElement().attribute("port");
                        net_plugin.databaseName = list.at(i).toElement().attribute("databaseName");
                        net_plugin.userName =list.at(i).toElement().attribute("userName");
                        net_plugin.passwd = list.at(i).toElement().attribute("password");
                        qDebug()<<net_plugin.status<<" "<<net_plugin.hostname<<" "<<net_plugin.port;
                    }
                }
            }
            else if (e.tagName() == "SerialPorts") {
                QDomNodeList list = e.childNodes();
                //qDebug()<<list.count()<<"serialPorts";
                for (int i = 0;i < list.count();i++) {
                    QDomElement temp = list.at(i).toElement();
                    qDebug()<<temp.tagName();
                    if (temp.tagName() == "SerialPort") {
                        Serial_port[temp.attribute("device")] = {temp.attribute("portName"),
                                temp.attribute("baudRate"),temp.attribute("dataBits"),temp.attribute("stopBits"),
                                temp.attribute("parity"),temp.attribute("writeBufferSize"),
                                temp.attribute("readBufferSize")};

                    }
                }
            }
            else if (e.tagName() == "Applications") {
                application_nums = e.attribute("number").toInt();
                QDomNodeList list = e.childNodes();
                for (int i = 0;i < list.size();i++) {
                    QDomElement temp = list.at(i).toElement();
                    if (temp.tagName() == "Application") {
                        app_name.push_back( {temp.attribute("logo"),temp.attribute("startup_args")});
                        qDebug()<<temp.attribute("startup_args");
                        app_button.push_back(new my_button());
                    }
                }
            }
        }
        n = n.nextSibling();
    }
    return net_plugin.status.toInt();
}
