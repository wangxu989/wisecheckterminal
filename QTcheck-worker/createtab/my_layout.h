#ifndef MY_LAYOUT_H
#define MY_LAYOUT_H
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QSet>
#include<QWidget>
#include<QQueue>
#include<QGroupBox>
//处理布局的递归操作
//当然也可以通过派生类实现（在构造函数内判断并加入Vector）此处写的通用一些
class layout_tool{
public:
    template<typename F>
    static void bfs_tool(QLayout* t,F f) {
        QQueue<QLayout*> q;
        q.push_back(t);
        while(!q.empty()) {
            QLayout* layout = q.front();
            q.pop_front();
            for(int i = 0;i < layout->count();i++) {
                QLayoutItem*tmp = layout->itemAt(i);
                if(tmp->widget() != nullptr) {
                    if(dynamic_cast<QGroupBox*>(tmp->widget()) != nullptr) {
                        q.push_back(dynamic_cast<QGroupBox*>(tmp->widget())->QWidget::layout());
                    }
                    else {
                        f(tmp->widget());
                    }
                }
                else if(tmp->layout() != 0){
                    q.push_back(tmp->layout());
                }
            }
        }
    }

};


class layout_base{

public:
    void add(){}
    template<typename T,typename... Types>
    void add(const T& t1,const Types&... t2) {
        rec.insert(reinterpret_cast<unsigned long>(t1));
        add(t2...);
    }
    QSet<unsigned long>rec;
    template<typename... Types>
    void hide_all(QLayout* layout,bool ifremove = false,const Types&... t){
        add(t...);
        for(int i = 0;i < layout->count();i++) {
            QLayoutItem* tmp = layout->itemAt(i);
            if(tmp->widget() != NULL) {
                QWidget* a = layout->itemAt(i)->widget();
//                                if(a->layout() != NULL) {
//                                    hide_all(a->layout(),ifremove);
//                                    continue;
//                                }
                if(rec.find(reinterpret_cast<unsigned long>(a)) != rec.end()) {
                    continue;
                }
                a->setVisible(false);
                if(ifremove==true) {
                    layout->removeWidget(a);
                }
            }
            else {
                if(rec.find(reinterpret_cast<unsigned long>(tmp->layout())) != rec.end()) {
                    continue;
                }
                hide_all(tmp->layout(),ifremove);
            }
        }
        if(sizeof...(t) > 0) {
            rec.clear();
        }
    }
    template<typename... Types>
    void un_hide_all(QLayout* layout,const Types&... t) {
        //rec.clear();
        add(t...);
        for(int i = 0;i < layout->count();i++) {
            QLayoutItem* tmp = layout->itemAt(i);
            if(tmp->widget() != NULL) {
                QWidget* a = layout->itemAt(i)->widget();
                if(rec.find(reinterpret_cast<unsigned long>(a)) != rec.end()) {
                    continue;
                }
                a->setVisible(true);
            }
            else {
                if(rec.find(reinterpret_cast<unsigned long>(tmp->layout())) != rec.end()) {
                    continue;
                }
                un_hide_all(tmp->layout());
            }
        }
        if(sizeof...(t) > 0) {
            rec.clear();
        }
    }

    virtual void hide(){};
    virtual void unhide(){};
};

class my_Hlayout:public layout_base, public QHBoxLayout{

public:
    void hide()override {
        for(int i = 0;i < this->layout()->count();i++) {
            QWidget* a = this->layout()->itemAt(i)->widget();
            a->setVisible(false);
        }
    }
    void unhide()override {
        for(int i = 0;i < this->layout()->count();i++) {
            QWidget* a = this->layout()->itemAt(i)->widget();
            a->setVisible(true);
        }
    }
};

#endif // MY_LAYOUT_H
