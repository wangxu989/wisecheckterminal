#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H
#include<QDebug>
/* 提供 右值/左值 构造/拷贝，由于左值拷贝 + 构造会产生 临时变量 eg:type<T> p = type<T>(new dritype()) ，且临时变量退栈会被析构造。
 如果构造计数为0,这个语句会产生 new,new_copy（此时引用计数为0 + 1 = 1）。退栈后引用计数为0,会导致单例构造无法传出，故添加右值操作，
返回值为void 也是基于此考量的结果*/
/* static bool 类型为这样做的代价（delete后无法修改val/cnt的地址）*/
template<typename T>
class my_shared_ptr
{
    typedef my_shared_ptr<T> type;
public:
    explicit my_shared_ptr(T* t,unsigned start = 1):val(t){
        if (t != nullptr) {
            status = false;
            cnt = new unsigned int(start);
            qDebug()<<"new cnt_num   "<<*cnt;
        }
    }
    my_shared_ptr(const type& t) {
        if (t.val == nullptr) {
            return;
        }
        this->val = t.val;
        this->cnt = t.cnt;
        (*(t.cnt))++;
        qDebug()<<"copy_new cnt_num   "<<*cnt;
    }

    T* data(){
        return val;
    }
    my_shared_ptr(type&& t) {
        this->val = t.val;
        this->cnt = t.cnt;
        t.val = nullptr;
        t.cnt = nullptr;
        qDebug()<<"copy_new&& cnt_num   "<<*cnt;
    }
    void operator=(type&& t){
        this->val = t.val;
        this->cnt = t.cnt;
        t.val = nullptr;
        t.cnt = nullptr;
        qDebug()<<"copy&& cnt_num   "<<*cnt;
    }

    void operator=(const type& t){
        if (t.val == nullptr){
            return *this;
        }
        this->val = t.val;
        this->cnt = t.cnt;
        (*(t.cnt))++;
        qDebug()<<"copy cnt_num   "<<*cnt;
    }
    ~my_shared_ptr() {
        if (val == nullptr) {
            return;
        }
        if (--(*cnt) == 0){
            delete cnt;
            delete val;
            status = true;//empty
        }
        qDebug()<<"delete cnt_num   "<<*cnt;
    }
    unsigned int get_cnt() {
        return *cnt;
    }
    T* operator->() {
        return val;
    }
    bool empty() {
        return status;
    }
    static bool status;//empty

private:
    T* val = nullptr;
    unsigned int *cnt = nullptr;
};

#endif // MY_SHARED_PTR_H
