#include "finish_work.h"
#include "ui_finish_work.h"
#include<QDebug>
#include<unordered_map>
#include<QFile>
my_time* my_time::time = nullptr;
extern database_server *data_server;
//计算工作时常
//
Program3::finish_work::finish_work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finish_work)
{
    ui->setupUi(this);
    layout = QSharedPointer<QHBoxLayout>(new QHBoxLayout());
    layout->addWidget(this);
    connect(ui->lineEdit_10,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_11,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_13,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_5,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_6,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_7,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_14,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    connect(ui->lineEdit_15,&MyLEdit::clicked,this,&Program3::finish_work::label_change);
    last_time = QSharedPointer<time_update>(new time_update(ui->lineEdit_5));
    now = ui->lineEdit_6;
    keyboard = QSharedPointer<keyboard_table>(new keyboard_table("Enter"));
    connect(keyboard.data(),&QTableWidget::cellClicked,this,&Program3::finish_work::in_keyboard);
    layout_tool::bfs_tool(this->QWidget::layout(),[&](QWidget*w){
        if(dynamic_cast<MyLEdit*>(w) != nullptr) {
            //qDebug()<<"OK";
            MyLEdit* e =  dynamic_cast<MyLEdit*>(w);
            int r,g,b;
            e->palette().background().color().getRgb(&r,&g,&b);
             qDebug()<<r<<" "<<g<<" "<<b;
            if(e->palette().background().color() == QColor(241,97,97)) {
                finish_need_warn.push_back(e);
            }
        }
    });
}
void Program3::finish_work::in_keyboard(int row, int column) {
    if (row == 0 && column == 3) {//delete
        now->setText(now->text().mid(0,now->text().size() - 1));
    }
    else if (row == 2 && column == 3) {//enter
        if(now == ui->lineEdit_14) {
            insert_IR(ui->lineEdit_14->text());
        }
        if(now == ui->lineEdit_15) {
            insert_Probatch(ui->lineEdit_15->text());
        }
        //移除键盘
        switch (keyboard_model){
        case Normal:
            ret_keyboard();
            break;
        case WaitForDeal:
            ret_keyboard_waitfordeal();
            enter->setVisible(true);
            break;
        default:
            qDebug()<<"error: undefined enum";
        }
        if (!ui->lineEdit_13->isEnabled()) {
            ui->lineEdit_13->setEnabled(true);
        }
        if (!ui->lineEdit_11->isEnabled()) {
            ui->lineEdit_11->setEnabled(true);
        }
    }
    else {
        now->setText(now->text() + keyboard->item(row,column)->text());
    }
}

void Program3::finish_work::insert_YG(const QString& s) {
    ui->lineEdit_16->setText(s);
}
void Program3::finish_work::insert_YG_N(const QString& s) {
    ui->lineEdit_17->setText(s);
}
void Program3::finish_work::insert_SB(const QString& s) {
    ui->lineEdit_2->setText(s);
}
void Program3::finish_work::insert_SB_N(const QString& s) {
    ui->lineEdit_18->setText(s);
}
void Program3::finish_work::insert_SB_Department(const QString& s) {
    ui->lineEdit_21->setText(s);
}
void Program3::finish_work::insert_ZL(const QString& s) {
    ui->lineEdit_3->setText(s);
}
void Program3::finish_work::insert_Elf(const QString& s) {
    ui->lineEdit_12->setText(s);
}
void Program3::finish_work::insert_IR(const QString& s) {
    QFile f("./data/batch.txt");
    if(!f.open(QIODevice::ReadOnly)) {
        Mremind->show("no such file IR");
    }
    QString pre =  f.readLine();
    QString end = f.readLine();
    ui->lineEdit_14->setText(pre + s + end);
}
void Program3::finish_work::insert_Probatch(const QString& s) {
    QFile f("./data/batch.txt");
    //f.seek()
    if(!f.open(QIODevice::ReadOnly)) {
        Mremind->show("no such file batch");
    }
    f.readLine();
    f.readLine();
    QString pre = f.readLine();
    ui->lineEdit_15->setText(pre + s);
}

Program3::finish_work::~finish_work()
{

    delete ui;
}
QString Program3::finish_work::text() const{
    if (now == nullptr) {return QString("");}
    qDebug()<<now->text();
    return now->text();
}
bool Program3::finish_work::setText(const QString&s) {
    if (now == nullptr) {return false;}
    qDebug()<<"Mylineedit";
    now->setText(s);
    return true;
}
void Program3::finish_work::insert_waitfordeal(const QString& s){
    ui->lineEdit_7->setText(s);
}
void Program3::finish_work::set_finishtime(const QString&s) {
    ui->lineEdit_10->setText(s);
}

//点击键盘事件
void Program3::finish_work::label_change(MyLEdit *m) {
    qDebug()<<"click in";
    if(m == ui->lineEdit_15) {
        call_keyboard();
    }
    if(m == ui->lineEdit_14) {
        call_keyboard();
    }
    //待处理
    static std::unordered_map<unsigned long,QHBoxLayout*>store_layout;
    static std::unordered_map<unsigned long, QLabel*>store_id;
    store_layout.clear();
    if (m == ui->lineEdit_7) {
        qDebug()<<"waitfordeal";
        keyboard.data()->setVisible(false);
        waitfordeal = new QVBoxLayout();
        wfd = new QFrame();
        QSqlQuery query = data_server->query_ctl("select * from discardtypetab");
        waitfordeal_type data;
        while(query.next()) {
            data.id = query.value(0).toString();
            data.type = query.value(1).toString();
            QHBoxLayout* tmp = new QHBoxLayout();
            QFont t;
            t.setPointSize(20);
            QLabel* id = new QLabel(data.id);
            id->setFont(t);
            //id->setFixedSize(height,width);
            QLabel* type = new QLabel(data.type);
            type->setFont(t);
            //type->setFixedSize(height,width);
            t.setPointSize(22);
            MyLEdit* edit = new MyLEdit();
            edit->setFont(t);
            //edit->setFixedSize(height,width);
            store_layout[reinterpret_cast<unsigned long>(edit)] = tmp;
            store_id[reinterpret_cast<unsigned long>(edit)] = id;
            tmp->addWidget(id);
            tmp->addWidget(type);
            tmp->addWidget(edit);
            tmp->setStretchFactor(id,1);
            tmp->setStretchFactor(type,2);
            tmp->setStretchFactor(edit,1);
            waitfordeal->addItem(tmp);
            connect(edit,&MyLEdit::clicked,this,[&](MyLEdit* m)->void{
                layout_deal.hide_all(wfd->layout(),false,store_layout[reinterpret_cast<unsigned long>(m)]);
                ui->verticalLayout_11->addWidget(keyboard.data());
                keyboard.data()->setVisible(true);
                enter->setVisible(false);
                //m->setVisible(true);
                now = m;
                keyboard_model = WaitForDeal;
            });
        }
        hide();
        hide_write();
        wfd->setStyleSheet(" \
                           frame{border:2px; solid #000000} \
                           background:transparent; \
                border:1px solid #000000;");
        wfd->setLayout(waitfordeal);
        ui->verticalLayout_11->addWidget(wfd);
        if(enter == nullptr) {
            enter = new QPushButton("确定");
            enter->setFixedSize(80,70);
            connect(enter,&QPushButton::clicked,this,[&]()->void{
                        end_string = "";
                        unhide();
                        unhide_write();
                        ui->verticalLayout_11->removeWidget(wfd);
                        ui->verticalLayout_11->removeWidget(enter);
                        wfd->setVisible(false);
                        enter->setVisible(false);
                        int cnt = 0;
                        QString temp_s;
                        int type_cnt = 0;
                        for(auto&a:store_layout) {
                            MyLEdit* edit_tmp = reinterpret_cast<MyLEdit*>(a.first);
                            if(edit_tmp->text() > "0") {
                                cnt += edit_tmp->text().toInt();
                                type_cnt++;
                                temp_s += store_id[a.first]->text() + "," + edit_tmp->text() + ",";
                            }
                        }
                        end_string += QString::number(cnt) + "," + QString::number(type_cnt) + "," + temp_s.left(temp_s.size() - 1);
                        qDebug()<<end_string;
                        insert_waitfordeal(QString::number(cnt));
                        delete wfd;
                    });
        }
        enter->setVisible(true);
        ui->verticalLayout_11->addWidget(enter,0,Qt::AlignRight);
        return;
    }
    now = m;
    keyboard_model = Normal;
    //呼出键盘
    call_keyboard();
    if (m == ui->lineEdit_11) {
        ui->lineEdit_13->setEnabled(false);//热处理
        ui->lineEdit_13->setText("");
    }
    else if (m == ui->lineEdit_13) {//表面处理
        ui->lineEdit_11->setEnabled(false);
        ui->lineEdit_11->setText("");
    }
}
QString Program3::finish_work::getEndCount() {//成品数量
    return ui->lineEdit_6->text();
}
QString Program3::finish_work::getCurrentTime() {
    QDateTime dateTime = QDateTime::currentDateTime();
    QLocale locale;//指定英文显示
    QString strFormat = "yyyyMMddhhmm";
    return locale.toString(dateTime, strFormat);
}
QString Program3::finish_work::get_Finish_Count() {//待处理数量
    return ui->lineEdit_7->text();
}
QString Program3::finish_work::get_Probatch() {//产品批次
    return ui->lineEdit_15->text();
}
bool Program3::finish_work::check() {
    QString& s = my_socket->workInfo.instruction_id;
    QString instructionID;
    if (s.contains("ZL")) {//首次
        instructionID = s.split(",")[1];
    }
    else {
        instructionID = s.split(",")[0];
        //更新剩余数
        int residue_num = this->get_residueNum().toInt();
        int res = this->getEndCount().toInt() + this->get_Finish_Count().toInt();
        if(res > residue_num) {
            Mremind->show("非法输入：剩余数小于成品数+待处理数");
            return false;
        }
        QString q = QString("update planqrtab set ResidueNum = ResidueNum - " + QString::number(res) + " where s0 = '" + instructionID + "' and s2 = '" + s.split(",")[2] + "'");
        qDebug()<<s;
        qDebug()<<q;
        data_server->query_ctl(q);

    }
    if (ui->lineEdit_11->text() != "" && ui->lineEdit_13->text() != "") {
        Mremind->show("热处理和表面处理不能呢同时出现！");
        return false;
    }
    int f1 = ui->pushButton->text().toInt(),f2 = ui->pushButton_2->text().toInt();
    if (instructionID.right(2) == "01" && f2 > 1) {
        if (f1 < 0.9*f2)
        {
            QMessageBox messageBox(QMessageBox::NoIcon,
                                   "warnning", "成品数小于标箱数的90%%，请问成品数正确吗?",
                                   QMessageBox::Yes | QMessageBox::No, NULL); ;
            int result=messageBox.exec();
            if (result == QMessageBox::No) return false;
        }

        if (f1 > 1.1*f2)
        {
            QMessageBox messageBox(QMessageBox::NoIcon,
                                   "warnning", "成品数大于标箱数的1.1倍，请问成品数正确吗？",
                                   QMessageBox::Yes | QMessageBox::No, NULL); ;
            int result=messageBox.exec();
            if (result == QMessageBox::No) return false;
        }

    }
    for(auto&a:finish_need_warn) {
        if(a->text() == "") {
            Mremind->show("信息不全");
            //return false;
        }
    }
    GetBoxIndex(nPlanCappIndex,nBatchCappIndex,instructionID);
    return true;
}
QString Program3::finish_work::get_s10() {//热处理号
    return ui->lineEdit_11->text();
}
QString Program3::finish_work::get_s11() {//表面处理
    return ui->lineEdit_13->text();
}
QString Program3::finish_work::get_s12() {//检验报告
    return ui->lineEdit_14->text();
}
QString Program3::finish_work::get_sElesIf() {//备注信息
    //return ui->lineEdit_12->text();
}
QString Program3::finish_work::get_s16() {//装模清单
    return ui->lineEdit_20->text();
}
QString Program3::finish_work::get_worktime(){//工作时长
    return ui->lineEdit_10->text();
}
bool Program3::finish_work::check_s16() {
    //    QString temp = ui->lineEdit_9->text();
    //    if (temp.size() != 22) {
    //        Mremind->show("装模清单必须为22位数字字母组合");
    //        return false;
    //    }
    //    for (int i = 0;i < temp.size();i++) {
    //        //        if (temp[i] >= 'a' && temp[i] <= 'z') {
    //        //            temp[i] = 32;//65,97
    //        //        }
    //        if (!(temp[i] >= 'A' && temp[i] <= 'Z') || (temp[i] >= '1' && temp[i] <= '9')) {
    //            Mremind->show("装模清单必须为22位数字字母组合");
    //            return false;
    //        }
    //    }
    return true;
}

void Program3::finish_work::on_pushButton_clicked()//剩余数按钮
{

    ui->lineEdit_6->setText(get_residueNum());


}

QString Program3::finish_work::on_pushButton_2_clicked()
{
    //标箱数按钮
    QString& s = my_socket->workInfo.instruction_id;
    qDebug()<<s<<"   ZL";
    if (s.contains("ZL")) {
        QString temp = "select cStdCount from plansteptab where PlanStepID like " +  s.split(",")[1];
        QSqlQuery query = data_server->query_ctl(temp);
        qDebug()<<temp;
        while (query.next()) {
            ui->lineEdit_6->setText(query.value(0).toString());
            return query.value(0).toString();
        }
        //return "2900";
    }
    QString q = QString("select CountPerBox from planstart2tab where CmdID = " + s.split(",")[0] +
            " and EndTime = " +  s.split(",")[2]).arg(getEndCount());
    QSqlQuery query = data_server->query_ctl(q);
    while(query.next()) {
        QString cnt = query.value(0).toString();
        ui->lineEdit_6->setText(cnt);
    }
    return ui->lineEdit_6->text();
}
void Program3::finish_work::init(const QString& s) {//读取数据库数据配置显示项目7
    //    if (s.right(2) == "01") {
    //        ui->horizontalLayout_7->setEnabled(true);
    //    }
    //    else {
    //        ui->horizontalLayout_7->setEnabled(false);
    //    }
    //背景色黑：不需要录入该项
    //背景色白：需要录入
    //背景色灰：扫码录入
    QSqlQuery query = data_server->query_ctl(QString("SELECT cBatchNo, cCountRatio, EndCount,cMustQC FROM plansteptab WHERE PlanStepID = '%1'").arg(s));
    while(query.next()) {//产品批次是否需要强制录入
        QString cBatchNo = query.value(0).toString();
        QString cCountRatio = query.value(1).toString();
        QString EndCount = query.value(2).toString();
        QString cMustQC = query.value(3).toString();
        if (cBatchNo == "1") {
            ui->lineEdit_15->setStyleSheet("background-color:rgb(241,97,97)");
            finish_need_warn.push_back(ui->lineEdit_15);
        }
        if(cMustQC == "1") {
            ui->lineEdit_14->setStyleSheet("background-color:rgb(241,97,97)");
            finish_need_warn.push_back(ui->lineEdit_14);
        }
    }
}
bool Program3::finish_work::GetBoxIndex(int &nPlanCappIndex,int &nBatchCappIndex,const QString& s) {
    nPlanCappIndex = 0;
    nBatchCappIndex = 0;
    // 1 得到总是存在的计划箱号
    QSqlQuery query = data_server->query_ctl(QString("SELECT ExeBoxIndex,cProcessName FROM plansteptab WHERE PlanStepID = '%1'").arg(s));
    if (query.size() == 0)
    {
        Mremind->show("数据库中不存在该生产令码");
        return false;
    }
    while(query.next()) {
        int lval = query.value(0).toInt();
        processname = query.value(1).toString();
        nPlanCappIndex = lval + 1;
    }

    // 2 得到可能存在的批次箱号

    // 2.1 批次号为空，则不存在批次箱号
    if (ui->lineEdit_15->text() == "")
    {
        nBatchCappIndex = 0;
        return true;
    }
    // 2.2 批次号非空，则存在批次箱号
    else { // a 查询批次箱号
        query = data_server->query_ctl(QString("SELECT ExeBoxIndex FROM batchnotab "
                                               "WHERE BatchNo = '%1' AND CappStepID = '%2%3'").arg(ui->lineEdit_15->text(),s.left(8),s.right(2)));
    }
    // b 若存在，则得到后返回
    if (query.size() == 1)
    {
        nBatchCappIndex = query.value(0).toInt() + 1;
        return true;
    }

    // c 若不存在，则插入1行后返回
    data_server->query_ctl(QString("INSERT INTO batchnotab (BatchNo,CappStepID) VALUES "
                                   "('%1','%2%3')").arg(ui->lineEdit_15->text(),s.left(8),s.right(2)));
    nBatchCappIndex = 1;
    return true;
}
QString Program3::finish_work::get_residueNum() {
    QString& s = my_socket->workInfo.instruction_id;
    if (s.contains("ZL")) {
        //Mremind->show("首道工序无剩余数");
        return QString("0");
    }
    //更新剩余数
    QString q = QString("select ResidueNum from planqrtab where s0 = '" + s.split(",")[0] + "'" + " and s2 = '" +  s.split(",")[2] + "'");//.arg(getEndCount());
    qDebug()<<q;
    QSqlQuery query = data_server->query_ctl(q);
    if(query.size() == 0) {
        Mremind->show("找不到完工记录!");
        return QString();
    }
    while(query.next()) {
        return query.value(0).toString();
    }
}
void Program3::finish_work::hide() {
    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->groupBox_3->setVisible(false);
}
void Program3::finish_work::unhide() {
    ui->groupBox->setVisible(true);
    ui->groupBox_2->setVisible(true);
    ui->groupBox_3->setVisible(true);
}
void Program3::finish_work::hide_write(){
    ui->groupBox_4->setVisible(false);
}
void Program3::finish_work::unhide_write(){
    ui->groupBox_4->setVisible(true);
}
void Program3::finish_work::call_keyboard()
{
    hide();
    keyboard.data()->setVisible(true);
    ui->verticalLayout_11->addWidget(keyboard.data());//添加键盘
    ui->verticalLayout_11->setStretchFactor(ui->groupBox_4,4);
    ui->verticalLayout_11->setStretchFactor(keyboard.data(),5);
}
void Program3::finish_work::ret_keyboard() {
    unhide();
    //移除键盘
    keyboard.data()->setVisible(false);
    ui->verticalLayout_11->removeWidget(keyboard.data());
}
void Program3::finish_work::ret_keyboard_waitfordeal(){
    //wfd->setVisible(true);
    layout_deal.un_hide_all(wfd->layout());
    keyboard.data()->setVisible(false);
    ui->verticalLayout_11->removeWidget(keyboard.data());
}
