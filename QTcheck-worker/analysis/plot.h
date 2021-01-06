#ifndef PLOT_H
#define PLOT_H
#include<qcustomplot.h>

#include<set>
class Plot:public QCustomPlot
{
public:
    Plot();
    void insert();
    void add();
    void init();
    void timerEvent(QTimerEvent *e);
    void mid_filter();
private:
    QVector<float>val;
    std::set<float>max_heap,min_heap;
    
};

#endif // PLOT_H
