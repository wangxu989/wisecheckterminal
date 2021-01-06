#ifndef MY_TABLEWIDGET_H
#define MY_TABLEWIDGET_H
#include<QTableWidget>
#include<QHeaderView>
#include<QAbstractButton>
#include<QApplication>
#include<QStylePainter>
//使用variable template设计构造函数
class  my_table:public QTableWidget{
public:
    ~my_table()override{}
    //explicit my_table(const QString& name):corner_name(name){}
    int now_row = 0;
    template<typename... Types>
    my_table(QString name0,Types... T):name(name0){//:QTableWidget(parent) {
        horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
        //verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        setStyleSheet("selection-background-color: blue");//选中行颜色
        setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
        setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
        QAbstractButton *btn = this->findChild<QAbstractButton *>();
        if (btn) {
            btn->setText(QStringLiteral("序号"));
            btn->installEventFilter(this);
            //btn->setStyleSheet("QAbstractButton{text-align : right;}");
            QStyleOptionHeader opt;
            opt.text = btn->text();
            QSize s = (btn->style()->sizeFromContents(QStyle::CT_HeaderSection, &opt, QSize(), btn).expandedTo(QApplication::globalStrut()));
            if (s.isValid()){
                this->verticalHeader()->setMinimumWidth(s.width());
                //t->verticalHeader()->setMinimumSize(btn->size());
            }
        }
        //去掉横竖scrollbar
        this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //不可修改
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);

        this->setColumnCount(sizeof...(T));
        head_init(T...);
    }
    template<typename T>
    bool insert(T& tab) {//向表格插入数据
        this->setRowCount(now_row + 1);
        //qDebug()<<"列数    "<<this->columnCount();
        for (int i = 0;i < this->columnCount();i++) {
            if (!this->item(this->now_row,i)) {
                this->setItem(this->now_row,i,new QTableWidgetItem());
            }
            this->item(this->now_row,i)->setText(tab[i]);
            this->item(this->now_row,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            qDebug()<<tab[i];
        }
        this->now_row++;
        //qDebug()<<this->now_row;
        return true;
    }
    void clear_all() {
        this->setRowCount(0);
        now_row = 0;
    }

    void head_init(){
        this->setHorizontalHeaderLabels(list_head);
    }
    template<typename T,typename... Types>
    void head_init(const T& t1,const Types&... types) {
        list_head<<t1;
        qDebug()<<t1;
        head_init(types...);
    }
    bool eventFilter(QObject *o, QEvent *e) {
        if (e->type() == QEvent::Paint)
        {
            QAbstractButton* btn = qobject_cast<QAbstractButton*>(o);
            if (btn)
            {
                // paint by hand (borrowed from QTableCornerButton)

                QStyleOptionHeader opt;
                opt.init(btn);
                QStyle::State state = QStyle::State_None;
                if (btn->isEnabled())
                    state |= QStyle::State_Enabled;
                if (btn->isActiveWindow())
                    state |= QStyle::State_Active;
                if (btn->isDown())
                    state |= QStyle::State_Sunken;
                opt.textAlignment = Qt::AlignCenter;//居中
                opt.state = state;
                opt.rect = btn->rect();
                opt.text = btn->text(); // this line is the only difference to QTableCornerButton

                opt.position = QStyleOptionHeader::OnlyOneSection;
                QStylePainter painter(btn);
                painter.drawControl(QStyle::CE_Header, opt);
                return true; // eat event

            }
        }
        return false;
    }

    my_table& operator =(const my_table& t1)=delete;
    my_table(const my_table& t1)=delete;

private:
    QString corner_name;
    QStringList list_head;
    QString name;
};

#endif // MY_TABLEWIDGET_H
