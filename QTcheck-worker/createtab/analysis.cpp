#include "analysis.h"
#include "ui_analysis.h"

analysis::analysis(const QString& name,QWidget *parent) :
    //MyWidget(parent),
    ui(new Ui::analysis),
    baseP(name)
{
    ui->setupUi(this);
}

analysis::~analysis()
{
    delete ui;
}
bool analysis::start_P() {

}
void analysis::finish_P() {

}
MyWidget* analysis::get_widget(){
    return this;
}


