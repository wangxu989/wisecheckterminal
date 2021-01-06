#ifndef GLOBAL_FUN_H
#define GLOBAL_FUN_H
#include<keyboard_base.h>
#include<finish_work.h>
#include<QVBoxLayout>
#include<startwork.h>
//键盘类，由于键盘的显示在需求中有变化，这里抽象显示基类统一接口（setText,text,setFont...）策略+工厂+装饰使用显示。
class baseLabel{//装饰模式
public:
    virtual QString text() = 0;
    virtual bool setText(const QString& s) = 0;
    virtual void setStyleSheet(const QString& s) = 0;
    virtual void setFont(QFont) = 0;
    virtual QWidget* get_widget() = 0;
    virtual void setVisible(bool status){};
    ~baseLabel(){}
};
class base_factory_label{
public:
    virtual baseLabel* Concrete() = 0;
    virtual ~base_factory_label(){};
};

class normal_label:public baseLabel {//正常的label
public:
    normal_label() {
        display = QSharedPointer<QLabel>(new QLabel());
    }
    void operator = (const normal_label&) = delete;
    normal_label(const normal_label&) = delete;
    QString text()override{
        return display->text();
    }
    bool setText(const QString& s)override {
        display->setText(s);
        return true;
    }
    void setStyleSheet(const QString&s)override{
        display->setStyleSheet(s);
    }
    void setFont(QFont f) {display->setFont(f);}
    QWidget* get_widget(){return display.data();}
    void setVisible(bool status)override{display->setVisible(status);};
private:
    QSharedPointer<QLabel> display;
};
class normal_label_factory:public base_factory_label{
public:
    baseLabel* Concrete() {
        return new normal_label();
    }
};


class composite_label:public baseLabel{//一堆label(Program3::finish_work)
public:
    composite_label() {
        display = QSharedPointer<Program3::finish_work>(new Program3::finish_work());
    }
    QString text()override{
        qDebug()<<"text";
        return display->text();
    }
    bool setText(const QString& s)override {
        display->setText(s);
        return true;
    }
    void setStyleSheet(const QString &s){}
    void setFont(QFont){}
    QWidget* get_widget(){return display.data();}
private:
    QSharedPointer<Program3::finish_work> display;

};

class composite_label_factory:public base_factory_label {
public:
    baseLabel* Concrete() {
        return new composite_label();
    }
};

class start_work_label:public baseLabel{
public:
    start_work_label() {
        display = QSharedPointer<startwork>(new startwork());
    }
    void operator = (const startwork&) = delete;
    start_work_label(const startwork&) = delete;
    QString text()override{
        return display->text();
    }
    bool setText(const QString& s)override {
        display->setText(s);
        return true;
    }
    void setStyleSheet(const QString&s)override{
        display->setStyleSheet(s);
    }
    void setFont(QFont f) {display->setFont(f);}
    QWidget* get_widget(){return display.data();}
private:
    QSharedPointer<startwork> display;
};

class startwork_label_factory:public base_factory_label {
public:
    baseLabel* Concrete() {
        return new start_work_label();
    }
};
class keyboard_widget:public QWidget {
public:
    keyboard_table*figure;
    ~keyboard_widget(){
        delete figure;
        delete fig_key;
        delete display;
    }
    QWidget* get_widget() {
        return figure;
    }
    baseLabel* get_display() {
        return display;
    }
    keyboard_widget(const QString& s,base_factory_label* factory = new normal_label_factory(),bool ifshow = true) {
        display = factory->Concrete();
        display->setStyleSheet("border:2px solid black;");
        QFont ft;//字体大小
        ft.setPointSize(30);
        display->setFont(ft);
        figure = new keyboard_table(s,4,4);
        fig_key = new QVBoxLayout();
        fig_key->addWidget(display->get_widget());
        fig_key->addWidget(figure);
        fig_key->setStretchFactor(display->get_widget(),1);
        fig_key->setStretchFactor(figure,4);
        this->setLayout(fig_key);
        QLabel *t_label = new QLabel();
        t_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        t_label->setPixmap(QPixmap(":/new/prefix1/img/cancel.png"));
    }
    inline void setText(const QString& s) {display->setText(s);}
    inline void removeText() {display->setText(display->text().mid(0,display->text().size() - 1));}
    inline QString getVal()const {return display->text();}
    inline void addText(int row,int column,const QString&& s = ""){display->setText(display->text() + figure->item(row,column)->text() + s);}
    inline void flash(){last_query = display->text();}
    inline QString lastquery()const{return last_query;}
    inline QVBoxLayout* layout() const{return fig_key;}
    inline void setlabelVisible(bool status){display->setVisible(status);}
    //inline baseLabel* get_label() {return baseLabel;}
private:
    baseLabel *display;
    QVBoxLayout *fig_key;
    QString last_query;

};

#endif // GLOBAL_FUN_H
