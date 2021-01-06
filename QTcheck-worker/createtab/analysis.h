#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QWidget>
#include<base_program.h>
namespace Ui {
class analysis;
}

class analysis : public MyWidget,public baseP
{
    Q_OBJECT

public:
    explicit analysis(const QString& name,QWidget *parent = 0);
    ~analysis();
    bool start_P();
    void finish_P();
    MyWidget* get_widget();
private:



private:
    Ui::analysis *ui;
};

#endif // ANALYSIS_H
