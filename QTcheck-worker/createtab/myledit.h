#ifndef MYLABEL_H
#define MYLABEL_H
#include<QWidget>
#include<QLineEdit>
#include<QMouseEvent>
//将program3完工界面中的QLineEdit提升为自己的类重写mouseReleaseEvent事件实现点击事件
class MyLEdit:public QLineEdit{
    Q_OBJECT
public:
    MyLEdit(QWidget*w=nullptr):QLineEdit(w){
        //this->setStyleSheet("background-color:rgb(255,255,0)");
    };
protected:
    virtual void mouseReleaseEvent(QMouseEvent *e) {
        //Q_UNUSED(e);
        if(e->button()== Qt::LeftButton) {
            emit clicked(this);
        }

    }
signals:
    void clicked(MyLEdit*);
};

//点击接受扫码
class ScanLEdit:public QLineEdit{
    Q_OBJECT
public:
    ScanLEdit(QWidget*w=nullptr):QLineEdit(w){

    };
protected:
    virtual void mouseReleaseEvent(QMouseEvent *e) {
        if(e->button() == Qt::LeftButton) {
            emit clicked(this);
        }
    }
signals:
    void clicked(ScanLEdit*);
};

#endif // MYLABEL_H
