#include<mainwindow.h>
#include<programwork.h>
#include<QTime>
#include<QPushButton>
#include<QPixmap>
#include"socket.h"
#include<ui_programwork.h>
//全局double比较
const double eps = 1e-10;//double 比较精度
bool cmp_eq(const double& a,const double& b) {
    return a - b >= -eps && b - a >= -eps;
}

bool cmp_eg (const double& a,const double& b) {
    return a - b >= -eps;
}

extern int mode;
extern database_plugin net_plugin;
extern database_server *data_server;//数据库类
extern database_local *data_local;
static double valuel2 = 0;
static volatile int myrow = 0,mycolumn = 0;//记录一级表格的点击位置
static int people_flag = 1;
static int modify = 0;
//static int mode;
static int keyboard_flag = 0;
QMap<QString,event_progressbar*> event_progressbar::progressbars;
ProgramWork::~ProgramWork()
{
    my_process.close();
    delete pro_bar;
    delete button_ret;
    delete narrow;
    delete enlarge;
    delete gauge;
    delete messageBox;
    delete ui;
    delete temp;
    delete templayout;
    delete tempw;
    delete v_layout;
    delete v_button_layout;
    delete layout;
    //    delete widget;//由于线程不会立马被结束，需要赞留界面。用智能指针

    //    delete data_local;
    //    delete data_server;
}
ProgramWork::ProgramWork(const QString& name,QWidget *parent)
    :  //QWidget(parent)
    ui(new Ui::ProgramWork),
    baseP(name)
{
    progress_bar = QSharedPointer<progressbar1>(new progressbar1(QString("first")));
     ui->setupUi(this);

     //qRegisterMetaType<my_tablewidget>("my_tablewidget");
     //登录界面
}
bool ProgramWork::start_P() {
    qDebug()<<"start P1";
    return listen();
}
void ProgramWork::finish_P() {
    remove_P(name_P);
    system("killall mainwindow");
    //delete this;
}

void ProgramWork::check_identity() {//接收核验成功的信号
    //qDebug()<<"check identity";
    result = QMessageBox::Yes;
    messageBox->close();
}
bool ProgramWork::listen() {
    //my_socket = new socket();//开启监听
    if (my_socket->status()) {
        login();
        return true;
    }
    else {
        bool ret = my_socket->bind();
        if (ret == true) {login();}
        return ret;
    }
}
void ProgramWork::login() {
    messageBox = new QMessageBox(QMessageBox::NoIcon,"title","重新录入请【返回】,巡检员需扫【员工码】",QMessageBox::No,NULL);
    messageBox->button(QMessageBox::No)->setText("返回");
    messageBox->setStyleSheet("QLabel{min-width:400 px; font-size: 18px;} QPushButton{ width:80px; font-size: 24px; }");
    //超差键盘,有待改进，键盘封装为一个类
    keyboard = new keyboard_widget("Enter");

    connect(keyboard->figure,&my_tablewidget::cellClicked,this,&ProgramWork::in_keyboard);
    connect(my_socket,&socket::start_work,this,&ProgramWork::start_work);
    connect(my_socket,&socket::check_identity,this,&ProgramWork::check_identity);
    connect(my_socket,SIGNAL(check_info(int)),this,SLOT(check_info(int)));
    //开启图表进程
    //QStringList argument;
#ifdef MY_P
    my_process.start("./plugin/mainwindow");
#else
    my_process.startDetached("./plugin/1.sh");

#endif
}
void ProgramWork::draw_init() {
    //buttonej = new QPushButton("返回");
    tempw = new QWidget();//二级表格父widget
    templayout = new QHBoxLayout();//二级表格布局
    temp = new QTableWidget();//二级表格
    connect(temp,SIGNAL(cellClicked(int,int)),this,SLOT(ejClicked(int,int)));
    templayout->addWidget(temp);
    //templayout->addWidget(buttonej);
    //connect(buttonej,SIGNAL(clicked()),this,SLOT(pushButtonclickedej()));
    tempw->setLayout(templayout);


    const int button_height = 100;
    const int button_width = 70;

    button_ret = new QPushButton();
    button_ret->setIcon(QIcon(":/new/prefix1/img/exit.png"));
    button_ret->setFixedSize(button_width,button_height);
    button_ret->setIconSize(QSize(50,50));

    narrow = new QPushButton();
    enlarge = new QPushButton();
    gauge = new QPushButton("检具");
    //cp = new QPushButton("CP");
    //cpk = new QPushButton("CPK");
    //connect(cp,&QPushButton::clicked,this,&ProgramWork::cp_deal);
    //connect(cpk,&QPushButton::clicked,this,&ProgramWork::cpk_deal);
    //cp->setFixedSize(button_width,button_height);
    //cpk->setFixedSize(button_width,button_height);
    gauge->setFixedSize(button_width,button_height);
    enlarge->setIcon(QIcon(":/new/prefix1/img/+.png"));
    narrow->setIcon(QIcon(":/new/prefix1/img/-.png"));
    narrow->setIconSize(QSize(50,50));
    narrow->setFixedSize(button_width,button_height);
    enlarge->setIconSize(QSize(50,50));
    enlarge->setFixedSize(button_width,button_height);
    //connect(gauge,SIGNAL(clicked(),this,SLOT());
    connect(narrow,SIGNAL(clicked()),this,SLOT(plot_narrow()));
    connect(enlarge,SIGNAL(clicked()),this,SLOT(plot_enlarge()));
    connect(gauge,&QAbstractButton::clicked,this,&ProgramWork::gauge_add);

    connect(button_ret,&QAbstractButton::clicked,this,&ProgramWork::pushButton_finish);
    //connect(button_quit,&QAbstractButton::clicked,this,&ProgramWork::pushButton_exit);
    widget = new QWidget();


    v_layout = new QVBoxLayout();//布局进度条和tab
    v_button_layout = new QVBoxLayout();//布局按钮
    v_layout->addWidget(progress_bar->get_bar());
    v_layout->addWidget(&tab1);
    //v_button_layout->addWidget(button_quit);
    v_button_layout->addWidget(button_ret);
    v_button_layout->addWidget(enlarge);
    v_button_layout->addWidget(narrow);
    v_button_layout->addWidget(gauge);
    layout = new QHBoxLayout();//布局v_layout和button_layout
    layout->addLayout(v_layout);
    layout->addLayout(v_button_layout);
    layout->setStretchFactor(v_layout,10);
    layout->setStretchFactor(v_button_layout,1);
    widget->setLayout(layout);
}
void ProgramWork::gauge_add() {
    keyboard_flag = 2;
    emit MyWidget::change_widget(keyboard);
    keyboard->setText("");
}

void ProgramWork::prePage() {
    int maxValue = tab1.table[tabnum]->horizontalScrollBar()->maximum();
    int nCurScroller = tab1.table[tabnum]->horizontalScrollBar()->value();
    if (nCurScroller > 0) {
        tab1.table[tabnum]->horizontalScrollBar()->setSliderPosition(nCurScroller - pagevalue);

    }
    else {
        tab1.table[tabnum]->horizontalScrollBar()->setSliderPosition(maxValue);
    }
}
void ProgramWork::nextPage() {
    int maxValue = tab1.table[tabnum]->horizontalScrollBar()->maximum();
    int nCurScroller = tab1.table[tabnum]->horizontalScrollBar()->value();
    if (nCurScroller < maxValue) {
        tab1.table[tabnum]->horizontalScrollBar()->setSliderPosition(nCurScroller + pagevalue);

    }
    else {
        tab1.table[tabnum]->horizontalScrollBar()->setSliderPosition(0);
    }
}
void ProgramWork::start_work(){
    //    tabwidget = new QTabWidget();//一级表格
    tab1.setDocumentMode(true);//隐藏边框
    //tab1.tabWidget = tabwidget;//构造工作页面使用
    //单机版还是网络版
    qDebug()<<my_socket->workInfo.product_id<<"product_id";
    qDebug()<<my_socket->workInfo.worker_id<<"worker_id";
    qDebug()<<my_socket->workInfo.instruction_id<<"instruction_id";

    switch(mode) {
    case 0://单机版
        qDebug()<<"单机版";
        if (tab1.readxml(my_socket->workInfo) < 0) {//人员信息不匹配
            return;
        }
        break;

    case 1:
        data_server->tab = &tab1;
        data_server->workInfo = &my_socket->workInfo;
        data_server->read_data();//首先读取client_cfg配置文件
        if (data_server->flag >= 0){return;}
        break;
    }
    data_local->tab = &tab1;
    data_local->workInfo = &my_socket->workInfo;
    data_local->insert_record();
    //读取检具信息
    tab1.read_gauge(my_socket->workInfo);
    draw_init();
    qDebug()<<tab1.messageWorkerEvn.workerInfo.name;
    qDebug()<<tab1.messageWorkerEvn.localEnv.process_id<<"process_id";
//    data_local = new database(my_socket->workInfo,tab1);//保留本地工作信息
    my_socket->info = &tab1.info;
    my_socket->createinfo = &tab1.createinfo;

    if(my_socket->clientConnection) {
        my_socket->sendmessage(0);//图表信息
        qDebug()<<"send";
    }
    else {
        qDebug()<<"send failed!";
    }
    //表格配置已配置
    pro_bar = new process_bar(this);
    connect(pro_bar,&process_bar::flash_progressBar,this,&ProgramWork::flash);
    pro_bar->start();
    tab1.my.x.resize(tab1.table.size());
    tab1.my.y.resize(tab1.table.size());
    for (int i = 0;i < tab1.table.size();i++) {
        connect(tab1.table[i],SIGNAL(cellClicked(int,int)),this,SLOT(onClicked(int,int)));
        tab1.my.x[i].resize(tab1.table[i]->columnCount());
        tab1.my.y[i].resize(tab1.table[i]->columnCount());
    }
    connect(&tab1,&QTabWidget::currentChanged,this, &ProgramWork::tabchanged);
    emit MyWidget::change_widget(widget);
    qDebug()<<"start_work";
}
void ProgramWork::in_keyboard(const int &row,const int &column) {
    if (row == 0 && column == 3) {//delete
        keyboard->removeText();
    }
    else if (row == 2 && column == 3) {//enter

        if (keyboard_flag == 1) {
            valuel2  = keyboard->getVal().toDouble();
            QString temp = tab1.table[tab1.currentIndex()]->verticalHeaderItem(myrow)->text();
            double cmp;
            if (myrow == 0) {
                cmp = temp.split("<")[0].toDouble();
                if (cmp_eg(cmp , valuel2)) {//最大
                    QMessageBox box(QMessageBox::NoIcon,"keyboard","非法输入",NULL,NULL);
                    box.exec();
                }
                else {
                    insertvalue(myrow,tab1.currentIndex(),valuel2,mycolumn);
                }
            }
            else {
                cmp = temp.split("<")[1].toDouble();
                if (cmp_eg(valuel2 , cmp)){//最小
                    QMessageBox box(QMessageBox::NoIcon,"keyboard","非法输入",NULL,NULL);
                    box.exec();

                }
                else {
                    insertvalue(myrow,tab1.currentIndex(),valuel2,mycolumn);
                }
            }
        }
        else if (keyboard_flag == 2){
            qDebug()<<"检具录入";
            tab1.createinfo[tab1.currentIndex()].gauge = keyboard->getVal();
            my_socket->sendmessage(13,tab1.currentIndex(),(*my_socket->createinfo)[tab1.currentIndex()].gauge);
            tab1.modify_gauge(my_socket->workInfo,tab1.currentIndex());
        }
//        else if (keyboard_flag == 2){
//            qDebug()<<"检具录入";
//            tab1.createinfo[tab1.currentIndex()].gauge = keyboard->getVal();
//            my_socket->sendmessage(13,tab1.currentIndex(),(*my_socket->createinfo)[tab1.currentIndex()].gauge);
//            tab1.modify_gauge(my_socket->workInfo,tab1.currentIndex());
//        }
        emit MyWidget::change_widget(widget);
    }
    else {
        keyboard->addText(row,column);
    }

}
void ProgramWork::pushform_button() {
    show();
}

void ProgramWork::pushButtonclickedej(){//返回
    //    qDebug()<<"返回";
    //    emit change_widget(1);
}
void ProgramWork::pushButton_exit()//退出登录
{
    my_process.close();
    qDebug()<<"退出";
    this->finish_P();
    emit MyWidget::change_widget(nullptr);
}
void ProgramWork::pushButton_finish() {//完工
    emit MyWidget::change_widget(nullptr);
    this->finish_P();
}
void ProgramWork::start_after() {
    //    takeCentralWidget();
    //    setCentralWidget(widget);
    emit MyWidget::change_widget(widget);
}
void ProgramWork::onClicked(int row,int column) {//一级表格的槽函数（检测身份）
    myrow = row;
    mycolumn = column;
    tab1.table[tabnum]->setCurrentItem(NULL);//取消选中
    if (!time_check(column,0)) {
        return;
    }
    int i = tabnum;
    valuel2 = 0;
    //int flag;
    if (tab1.table[i]->flag[column].flag >= 1) {//此时为核验/修改
        //此处代码为二次赋值此时要判断身份
        messageBox->exec();
        result = result == QMessageBox::Yes?QMessageBox::Yes:messageBox->result();
        if (result == QMessageBox::Yes) {//审核员事件
            if (tab1.table[i]->flag[column].flag < 1) {
                return;
            }
            if (tab1.table[tabnum]->flag[column].checker_row_flag != -1) {
                modify = 1;
            }
            people_flag = 2;
        }
        else {//工人事件
            if (!time_check(column,1) || tab1.table[i]->flag[column].flag >= 2) {
                return;
            }
            people_flag = 1;
            modify = 1;
        }

    }
    else {
        modify = 0;
        people_flag = 1;
    }
    first_tablogic(row,column);
    result = QMessageBox::No;
}
void ProgramWork::first_tablogic(int &row,int &column) {//一级表格的逻辑部分
    int i = tabnum;
    if (row == 0 || row == tab1.table[i]->rowCount() - 1) {//警告值无二级精度
        if (cmp_eq(tab1.createinfo[tab1.currentIndex()].normvalue ,0)) {//OK/NG
            insertvalue(myrow,tab1.currentIndex(),valuel2,mycolumn);
        }
        else {
            keyboard_flag = 1;
            keyboard->setText("");
            emit MyWidget::change_widget(keyboard);
        }
        //return;
    }
    else if (tab1.createinfo[i].ejjddw != 0) {//绘制二级表格
        double flag;//获取当前单元格对应的误差值
        if (row != tab1.table[i]->rowCount() - 2) {
            flag = tab1.table[i]->verticalHeaderItem(row)->text().split("<")[0].toDouble();
        }
        else {
            flag = tab1.table[i]->verticalHeaderItem(row)->text().split("≤")[0].toDouble();
        }
        qDebug()<<flag;
        if (flag  <= tab1.createinfo[i].normvalue + tab1.createinfo[i].zgc){
            int sum = 0;
            qDebug()<<flag<<"flag"<<" "<<tab1.createinfo[i].normvalue + tab1.createinfo[i].zgc - tab1.createinfo[i].jddw;
            double cmp_0 = 0;
            if (cmp_eg(tab1.createinfo[i].normvalue + tab1.createinfo[i].zgc , flag + tab1.createinfo[i].jddw) ) {//当前误差值与最大公差间还有一级精度差
                sum = static_cast<int>(tab1.createinfo[i].jddw/tab1.createinfo[i].ejjddw);
            }
            else {
                sum =  static_cast<int>((tab1.createinfo[i].normvalue + tab1.createinfo[i].zgc - flag)/tab1.createinfo[i].ejjddw - 1);
            }
            qDebug()<<"sum"<<sum;
            int column_count = sum/10 > 0?10:sum%10;
            if (row == tab1.table[i]->rowCount() - 2) {
                column_count++;
            }
            temp->setColumnCount(column_count);
            temp->setRowCount(sum/10>0?sum/10:1);
            QStringList tlistv,tlisth;
            int j;
            if (row == tab1.table[i]->rowCount() - 2) {
                j = 0;
            }
            else {
                j = 1;
            }
            for (;j <= column_count;j++) {//水平表头
                double temp_value = j*tab1.createinfo[i].ejjddw;
                tlisth.append(tab1.auto_zero(tab1.createinfo[i].ejjddw,temp_value));
            }
            for (j = 0;j < temp->columnCount();j++) {//纵表头
                tlistv.append( tab1.auto_zero(tab1.createinfo[i].ejjddw,flag + 10*j*tab1.createinfo[i].ejjddw));//10*j*tab1.createinfo[i].ejjddw + tab1.createinfo[i].normvalue +  tab1.createinfo[i].fgc
            }
            temp->setVerticalHeaderLabels(tlistv);//纵表头
            temp->setHorizontalHeaderLabels(tlisth);//水平表头
            temp->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            //            this->takeCentralWidget();
            //            this->setCentralWidget(tempw);
            emit MyWidget::change_widget(tempw);
        }
    }
    else {
        insertvalue(row,i,valuel2,column);
    }
}
void ProgramWork::tabchanged(int i){//tab标签页切换
    tabnum = i;
    //if (i == tab1.scroll();)
    //QTime current_time = QTime::currentTime();
    //flash(current_time);
    if (my_socket->clientConnection){//已建立链接
        my_socket->sendmessage(1,i);
    }
}
void ProgramWork::ejClicked(int row,int column) {//二级表格点击信号槽函数
    if (myrow == tab1.table[tabnum]->rowCount() -2) {
        valuel2 = (row*10+column)*tab1.createinfo[tabnum].ejjddw;
    }
    else {
        valuel2 = (row*10+column + 1)*tab1.createinfo[tabnum].ejjddw;
    }
    insertvalue(myrow,tabnum,valuel2,mycolumn);
    emit MyWidget::change_widget(widget);
}
int ProgramWork::insertvalue(int row,int i,double valuel2,int column) {//向队列写入值
    if (!time_check(mycolumn,0)) {
        return 0;
    }
    qDebug()<<QDateTime::currentDateTime().toString();
    //qDebug()tab1.createinfo[i].chk_warn_thr
    if (people_flag == 1) {//员工标识
        int flag = tab1.table[i]->flag[column].worker_row_flag;
        if (flag != -1) {
            qDebug()<<"操作员修改";
            tab1.table[i]->item(flag,mycolumn)->setText("");
            tab1.table[i]->item(flag,mycolumn)->setBackground(tab1.table[i]->flag[mycolumn].flash_flag == 1?tab1.color_scheme[5]:tab1.color_scheme[6]);
        }
        tab1.table[tabnum]->flag[mycolumn].flag = people_flag;
        tab1.table[tabnum]->flag[mycolumn].worker_row_flag  = myrow;//置该tab该row标志
    }
    else if (people_flag == 2){//审核员标识
        int flag = tab1.table[i]->flag[column].checker_row_flag;
        if (flag != -1) {
            qDebug()<<"核验员修改";
            if (flag == tab1.table[i]->flag[column].worker_row_flag) {//此时要保留操作员信息
                tab1.table[i]->item(flag,mycolumn)->setBackground(QBrush(tab1.table[i]->flag[column].temp_worker_color));
            }
            else {
                tab1.table[i]->item(flag,mycolumn)->setText("");
                tab1.table[i]->item(flag,mycolumn)->setBackground(tab1.table[i]->flag[mycolumn].flash_flag == 1?tab1.color_scheme[5]:tab1.color_scheme[6]);
            }
        }
        tab1.table[tabnum]->flag[mycolumn].flag = people_flag;
        tab1.table[tabnum]->flag[mycolumn].checker_row_flag = myrow;//置该tab该row标志
    }
    if (modify == 1) {//修改操作中的删除操作
        if (my_socket->clientConnection) {
            my_socket->sendmessage(3,tabnum,mycolumn,people_flag);
        }
    }
    //获取当前点击行对应的一级值
    QString temp = tab1.table[i]->verticalHeaderItem(row)->text();
    //qDebug()<<valuel2;
    if (cmp_eq(tab1.createinfo[tab1.currentIndex()].normvalue, 0)) {//OK/NG
        if (temp == "OK") {
            temp = "1";
        }
        else {
            temp = "-1";
        }
    }
    else {//其他
        if (cmp_eq(tab1.createinfo[tab1.currentIndex()].ejjddw,0)) {//无二级表格
            if (row == 0 || row == tab1.table[i]->rowCount() - 1) {
                temp = "0";
            }
            else if (row == tab1.table[i]->rowCount() - 2) {
                temp = temp.split("≤")[2];
            }
            else {
                temp = temp.split("≤")[1];
            }
            //qDebug()<<temp;
        }
        else {
            if (row == 0 || row == tab1.table[i]->rowCount() - 1) {
                temp = "0";
            }
            else if (row == tab1.table[i]->rowCount() - 2) {
                temp = temp.split("≤")[0];
            }
            else {
                temp = temp.split("<")[0];
            }
        }
    }
    qDebug()<<temp<<"        temp";
    tab1.my.tabnum = i;
    double insy = temp.toDouble() + valuel2;//测量总值

    if (my_socket->clientConnection){//增加点
        //qDebug()<<insy<<" "<<time1.toTime_t();
        my_socket->sendmessage(2,tabnum,mycolumn,QString::number(insy),QString::number(QDateTime::currentDateTime().toTime_t()),people_flag);//坐标值发给图表进程
    }
    else {
        qDebug()<<"send failed!";
    }
    if (cmp_eq(tab1.createinfo[tab1.currentIndex()].normvalue ,0)) {
         tab1.table[tabnum]->item(row,column)->setText(insy == 1 ?"OK":"NG");//插入表格
    }
    else {
        tab1.table[tabnum]->item(row,column)->setText(QString::number(insy));//插入表格
    }
    int flag_rlt = 0;
    if (people_flag == 1) {//操作员操作
        if (mode && modify == 1) {//修改操作，需要删除远程数据库的上一条数据：保证所有操作都被记录
            data_server->remove_t();
        }
        if (row == 0 || row == tab1.table[i]->rowCount() - 1) {
            if (cmp_eq(tab1.createinfo[tab1.currentIndex()].normvalue,0)) {
                if (tab1.table[i]->rowCount() - 1 == row) {
                     tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[2]));
                     if (mode&&data_server) {
                         data_server->spc_event("1000");//超差
                     }
                }
                else {
                     tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[0]));
                }
            }
            else {
                tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[2]));
                if (mode&&data_server) {
                    data_server->spc_event("1000");//超差
                }
            }
            flag_rlt = 2;
        }
        else if (row - 0 <= tab1.table[tab1.currentIndex()]->warn_thr || tab1.table[i]->rowCount() - 1 - row <= tab1.table[tab1.currentIndex()]->warn_thr){
            tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[1]));
            if (mode&&data_server) {
                data_server->spc_event("1001");//预警
            }
            flag_rlt = 1;
        }
        else {
            flag_rlt = 0;//正常值
            tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[0]));
        }
        if (modify == 0) {
            data_local->insert_data(insy,flag_rlt,0);//正常插入本地数据库
        }
        else {
            data_local->insert_data(insy,flag_rlt,1);//修改本地数据库数据
        }
        //存储当前操作的时间
        QTime t1  = QTime::currentTime();
        tab1.table[tabnum]->flag[mycolumn].t_time = t1.hour()*3600 + t1.minute()*60 + t1.second();
        if (tab1.table[tabnum]->val != -1 && insy > tab1.table[tabnum]->val) {//大于上一个时间的测量值（初始值为0）
            qDebug()<<"上个时间段值:"<<tab1.table[tabnum]->val;
            if(tab1.table[tabnum]->trend_plus_minus != 1) {//若不是正趋势则预警值置0并改为正趋势
                //暂存值操作
                tab1.table[tabnum]->temp_trend_plus_minus = 1;
                tab1.table[tabnum]->temp_trend_val = 2;
            }
            else {//是正趋势则++
                tab1.table[tabnum]->temp_trend_val =  tab1.table[tabnum]->trend_val + 1;
            }
        }
        else if (tab1.table[tabnum]->val != -1 && insy < tab1.table[tabnum]->val) {
            if(tab1.table[tabnum]->trend_plus_minus != -1) {//若不是负趋势则预警值置0并改为负趋势
                tab1.table[tabnum]->temp_trend_val = -2;
                tab1.table[tabnum]->temp_trend_plus_minus = -1;
            }
            else {//是负趋势则--
                tab1.table[tabnum]->temp_trend_val = tab1.table[tabnum]->trend_val - 1;
            }
        }
        else {//和上次相同也算
            if(tab1.table[tabnum]->trend_plus_minus == 1) {//正趋势
                tab1.table[tabnum]->temp_trend_val =  tab1.table[tabnum]->trend_val + 1;
            }
            else {//是负趋势
                tab1.table[tabnum]->temp_trend_val =  tab1.table[tabnum]->trend_val - 1;
            }

        }
        if (tab1.table[tabnum]->temp_trend_val >= tab1.info.trend_warn_win.toInt() || tab1.table[tabnum]->temp_trend_val <= tab1.info.trend_warn_win.toInt()*(-1) ) {
            qDebug()<<tab1.table[tabnum]->temp_trend_val<<"temp  趋势预警 real"<<tab1.table[tabnum]->trend_val;
            //预警
            QMessageBox box(QMessageBox::NoIcon,"trend_warn_win","趋势预警",NULL,NULL);
            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::red);
            box.setPalette(pa);
            box.setStyleSheet("QLabel{min-width:150 px; font-size: 30px;} QPushButton{ width:80px; font-size: 24px; }");
            box.exec();
            if (mode&&data_server) {
                data_server->spc_event("1003");
            }
        }
        tab1.table[tabnum]->temp_val = insy;
    }
    else if (people_flag == 2){//核验员
        if (tab1.table[i]->flag[mycolumn].worker_row_flag == myrow) {
            //核验与操作员数据一样
            tab1.table[i]->flag[column].temp_worker_color =  tab1.table[i]->item(row,column)->background().color();
            tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[7]));
        }
        else if (tab1.table[i]->flag[mycolumn].worker_row_flag - myrow < tab1.info.chk_warn_thr.toInt() &&  myrow - tab1.table[i]->flag[mycolumn].worker_row_flag < tab1.info.chk_warn_thr.toInt()) {
            //在预警值内
            qDebug()<<"核验预警值内";
            qDebug()<<tab1.info.chk_warn_thr;
            qDebug()<<tab1.info.chk_warn_thr<<"相减："<<tab1.table[i]->flag[mycolumn].worker_row_flag - myrow ;
            qDebug()<<tab1.info.chk_warn_thr<<"相减："<<-tab1.table[i]->flag[mycolumn].worker_row_flag + myrow ;
            tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[3]));
            if (mode&&data_server) {
                data_server->spc_event("1002");//巡检预警
            }
        }
        else {
            //超出预警值
            tab1.table[i]->item(row,column)->setBackground(QBrush(tab1.color_scheme[4]));
            flag_rlt = 1;
            if (mode&&data_server) {
                data_server->spc_event("1003");//巡检超差
            }
        }
        data_local->insert_data(insy,flag_rlt,2);//存入核验员值（修改和写入一样）
    }
    modify = 0;//人员信息恢复
    people_flag = 1;//等级标志恢复
    return 0;
}
int ProgramWork::time_check(int column,int flag) {//检查当前点击时间段是否有效,0无效1有效
    int i = tabnum;
    QTime currenttime = QTime::currentTime();
    QString time = tab1.table[i]->horizontalHeaderItem(column)->text();
    int table_time = time.split(":")[0].toInt()*3600 + time.split(":")[1].toInt()*60;
    if(time.split(":").size() > 2) {
        table_time += time.split(":")[2].toInt();
    }
    //qDebug()<<time<<" "<<currenttime;
    uint now = currenttime.hour()*3600 + currenttime.minute()*60 + currenttime.second();
    if (flag == 0 && (now  - table_time >= tab1.table[i]->gap || now < table_time)) {
        qDebug()<<"gap unvalid";
        return 0;
    }
    if (flag == 1 && (tab1.table[tabnum]->flag[mycolumn].t_time && now - tab1.table[tabnum]->flag[mycolumn].t_time > tab1.info.lock_time.toDouble()*60)) {
        //tab1.table[i]->trend_val = tab1.table[i]->temp_trend_val;//将真实趋势值写入
        qDebug()<<tab1.table[tabnum]->flag[mycolumn].t_time<<" "<<now<<"column: "<<mycolumn;
        return 0;
    }
    return 1;
}
void ProgramWork::flash() {//刷新进度条+工作表

    QTime current_time = QTime::currentTime();
    int i = tabnum;
    int hour = current_time.hour();
    int minute = current_time.minute();
    int now = hour*3600 + minute*60 + current_time.second();
    int j = (now - tab1.start_time > 0 ? now - tab1.start_time:now - tab1.start_time + 3600*24)/tab1.table[i]->gap;
    //    if (j == tab1.info.disp_element_cnt. - 1) {//最后一列需要翻页了

    //    }
    if (j >= tab1.info.disp_element_cnt.toInt()) {//最后一列需要翻页了
        qDebug()<<"翻页";
        tab1.start_time = (tab1.start_time + j*tab1.table[i]->gap)%(24*3600);
        tab1.flash_table(tab1.start_time);//
        j = (now - tab1.start_time)/tab1.table[i]->gap;
        //        for (int k = 0;k < tab1.table[i]->rowCount();k++) {
        //            tab1.table[i]->item(k,tab1.info.disp_element_cnt.toInt() - 1)->setBackground(QBrush(tab1.color_scheme[5]));//灰色
        //        }
    }
    //qDebug()<<j<<"now j";
    //int temp_j = j - 1;
    int temp_j = (j == 0? tab1.info.disp_element_cnt.toInt() - 1:j-1);
    if (tab1.table[i]->flag[temp_j].flash_flag == 0) {//刷新上个时间段
        qDebug()<<"真实值写入";
        for (int f = 0; f < tab1.table.size();f++) {
            for (int k = 0;k < tab1.table[f]->rowCount();k++) {
                if (tab1.table[f]->item(k,temp_j)->background() == QBrush(tab1.color_scheme[6])) {//白色
                    tab1.table[f]->item(k,temp_j)->setBackground(QBrush(tab1.color_scheme[5]));//灰色
                }
            }
            tab1.table[f]->val = tab1.table[f]->temp_val;//将上个时间段的真实值写入
            tab1.table[f]->trend_val = tab1.table[f]->temp_trend_val;//将上个时间段的真实趋势值写入
            tab1.table[f]->trend_plus_minus = tab1.table[f]->temp_trend_plus_minus;//将上个时间段的真实趋势标识写入
            if (temp_j == j - 1) {
                tab1.table[f]->flag[temp_j].flash_flag = 1;
            }
            else {
                tab1.table[f]->flag[temp_j].flash_flag  = -1;
            }
        }
    }
    if (tab1.table[i]->flag[j].recover_flag == 0) {//将本时间段恢复可编辑色
        qDebug()<<"recover flag"<<tab1.table[i]->flag[j].recover_flag;
        for (int f = 0;f < tab1.table.size();f++) {
            for (int k = 0;k < tab1.table[f]->rowCount();k++) {
                tab1.table[f]->item(k,j)->setBackground(QBrush(tab1.color_scheme[6]));//白色
            }

            tab1.table[f]->flag[j].recover_flag  = 1;
        }
        qDebug()<<"recover flag"<<tab1.table[i]->flag[j].recover_flag;
    }
    int table_time = tab1.table[i]->horizontalHeaderItem(j)->text().split(":")[0].toInt()*3600 + tab1.table[i]->horizontalHeaderItem(j)->text().split(":")[1].toInt()*60;
    if (tab1.table[i]->horizontalHeaderItem(j)->text().split(":").size() > 2) {
        table_time += tab1.table[i]->horizontalHeaderItem(j)->text().split(":")[2].toInt();
    }
    //if (now - table_time >=0 && now - table_time < tab1.table[i]->gap) {
    progress_bar->setValue((double)(now - table_time)/(double)tab1.table[i]->gap*100);
    //qDebug()<<progress_bar->value()<<" "<<(double)(now - table_time)/(double)tab1.table[i]->gap;
    //pro_bar.setStyleSheet("{ border:2px solid grey;border-radius:5px;text-align:center;}");
    if (tab1.table[i]->item(0,j)->background() == QBrush(QColor(Qt::gray))) {
        for (int k = 0;k < tab1.table[i]->rowCount();k++) {
            tab1.table[i]->item(k,j)->setBackground(QBrush(QColor(Qt::white)));
        }
    }
    //下面的翻页非当前版本刷新策略，可以忽略
    //        if (i >= tab1.table[i]->horizontalScrollBar()->value() + pagevalue) {//每一个新的工作时间到来需要判断是否翻页
    //            nextPage();
    //        }
    //progress_bar->update();
    //}
    //else {
    //}
    //}
    //sem.release();

}
void ProgramWork::check_info(int flag) {
    qDebug()<<"check_info"<<flag<<"mode :"<<mode;
    if (start_flag != 0) {
        return;
    }
    switch (flag) {
    case 1:
        //if (mode == 0) {
        if (tab1.read_local_authuser(my_socket->workInfo) == 0) {
            ret_checkout[0] = 1;
            if(my_socket->clientConnection) {
                my_socket->sendmessage(5,tab1.messageWorkerEvn.workerInfo);
                qDebug()<<"send workerinfo!";
            }
            else {
                qDebug()<<"send failed!";
            }
        }
        else {
            my_socket->sendmessage(8);
        }
        //}
        // else if (mode == 1) {


        // }
        qDebug()<<tab1.messageWorkerEvn.workerInfo.name;
        break;
    case 2:
        //if (mode == 0) {
        if (tab1.readxml(my_socket->workInfo,1) == 0) {
            ret_checkout[1] = 1;
            if (tab1.read_local_env(my_socket->workInfo,0)==0) {

                if(my_socket->clientConnection) {
                    my_socket->sendmessage(6,tab1.messageWorkerEvn.localEnv);//图表信息
                    qDebug()<<"send workinfo!";
                    qDebug()<<tab1.messageWorkerEvn.localEnv.workstation;
                }
                else {
                    qDebug()<<"send failed!";
                }
            }
        }
        else {
            my_socket->sendmessage(9);
        }
        //}
        //else if (mode == 1) {

        //}

        break;
    case 3:
        //if (mode == 0) {
        if (tab1.read_local_env(my_socket->workInfo,1)==0) {
            if(my_socket->clientConnection) {
                my_socket->sendmessage(7,tab1.messageWorkerEvn.equip);
                qDebug()<<"send equipinfo!";
            }
            else {
                qDebug()<<"send failed!";
            }
            ret_checkout[2] = 1;
        }
        else {
            my_socket->sendmessage(10);
        }
        //}
        //else if (mode == 1) {

        //}
        break;
    }
    if (start_flag == 0&& ret_checkout[0] == 1 && ret_checkout[1] == 1 && ret_checkout[2] == 1) {
        start_work();
        qDebug()<<"start";
        start_flag = 1;
    }
}
void ProgramWork::plot_enlarge() {
    my_socket->sendmessage(11);
}
void ProgramWork::plot_narrow() {
    my_socket->sendmessage(12);
}

void ProgramWork::on_pushButton_clicked()
{
     emit MyWidget::change_widget(nullptr);
     system("killall mainwindow");
}
void ProgramWork::cp_deal() {
    my_socket->sendmessage(14);
}
void ProgramWork::cpk_deal() {
    my_socket->sendmessage(15);
}
