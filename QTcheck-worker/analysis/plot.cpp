#include "plot.h"
#include<queue>
#include<iostream>
const int N = 1000;
const int windows = 5;
Plot::Plot()
{
    init();
    this->startTimer(1000);
}
void Plot::init() {
    val.resize(N);
    for (int i = 0;i < N;i++) {
        int temp = rand()%10;
        if (i%10 == 0) {
            val[i] = rand()%N;
        }
        else {
            val[i] = i*i;
        }
    }
    this->addGraph();//原图
    this->addGraph();//中值滤波
     //this->addGraph();//中值滤波
    this->graph(1)->setPen(QPen(Qt::red));
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);//日期做X轴
    dateTicker->setDateTimeFormat("hh:mm:ss\nyy-MM-dd");//日期格式(可参考QDateTime::fromString()函数)
    this->xAxis->setTicker(dateTicker);//设置X轴为时间轴
    this->yAxis->setRange(0,10000);
    this->xAxis->setRange(QDateTime::currentDateTime().toTime_t()-60,QDateTime::currentDateTime().toTime_t() + 60);
    this->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectPlottables|QCP::iMultiSelect);

}
void Plot::timerEvent(QTimerEvent *e) {
    static int num = windows - 2;
    uint x = QDateTime::currentDateTime().toTime_t();
    float y = val[num++];
    uint time1 = QDateTime::currentMSecsSinceEpoch();
    //大小堆（使用set）取中值，第一次nlogn,以后logn。超快，在100001的数据量下0微秒，最小堆比较100微秒左右（第一次时间差不多）。
    if (num == windows - 1) {//第一次维护堆
        for (int i = 0;i <= num;i++) {
            if (max_heap.empty()) {
                max_heap.insert(val[i]);
            }
            else {
                if (val[i] > (*(--max_heap.end()))) {
                    min_heap.insert(val[i]);
                }
                else {
                    max_heap.insert(val[i]);
                }
                while(max_heap.size() > min_heap.size() + 1) {
                    min_heap.insert(*(--max_heap.end()));
                    max_heap.erase(--max_heap.end());
                }
                while(min_heap.size() > max_heap.size() + 1) {
                    max_heap.insert(*min_heap.begin());
                    min_heap.erase(min_heap.begin());
                }
            }
        }
        this->graph(1)->addData(x-windows,min_heap.size() > max_heap.size() ?*min_heap.begin():*(--max_heap.end()));
    }
    else if (num > windows - 1){
        if (min_heap.find(val[num - windows]) != min_heap.end()) {
            min_heap.erase(min_heap.find(val[num - windows]));
        }
        else {
            max_heap.erase(max_heap.find(val[num - windows]));
        }
        if (val[num] > (*(--max_heap.end()))) {
            min_heap.insert(val[num]);
        }
        else {
            max_heap.insert(val[num]);
        }
        while(max_heap.size() > min_heap.size() + 1) {
            min_heap.insert(*(--max_heap.end()));
            max_heap.erase(--max_heap.end());
        }
        while(min_heap.size() > max_heap.size() + 1) {
            max_heap.insert(*min_heap.begin());
            min_heap.erase(min_heap.begin());
        }
        this->graph(1)->addData(x,min_heap.size() > max_heap.size() ?*min_heap.begin():*(--max_heap.end()));
    }
    uint time2 =  QDateTime::currentMSecsSinceEpoch();;
    qDebug()<<"my_algorithm:"<<time2 - time1<<(min_heap.size() > max_heap.size() ?*min_heap.begin():*(--max_heap.end()));
//    std::priority_queue<float,std::vector<float>,std::greater<float> >q;
//    uint time3 =  QDateTime::currentMSecsSinceEpoch();
//    int newlen = (windows + 1)/2;
//    if (num >= windows - 1) {
//        for (int i = 0;i < newlen;i++) {
//            q.push(val[num - windows + 1 + i]);
//        }
//        for (int i = newlen;i < windows;i++) {
//            if (val[num - windows + 1 + i] > q.top()) {
//                q.pop();
//                q.push(val[num - windows + 1 + i]);
//            }
//        }
//        this->graph(2)->addData(x - windows,q.top());
//        uint time4 =  QDateTime::currentMSecsSinceEpoch();
//        qDebug()<<"laji_algorithm:"<<time4 - time3<<"    "<<q.top();
//    }
    this->graph(0)->addData(x,y);

    this->xAxis->setRange(x - 30, x + 30);
    this->replot(QCustomPlot::rpQueuedReplot);
}
