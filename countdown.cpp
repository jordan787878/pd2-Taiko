#include "countdown.h"
#include<QFont>
Countdown::Countdown(const int n, QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    counttime = n;


    setPlainText(QString("Time: " + QString::number(counttime)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",15,15));

    timer_count = new QTimer(this);
    connect(timer_count,SIGNAL(timeout()),this,SLOT(timedecrease()));
    timer_count->start(1000);
}

void Countdown::timedecrease()
{
    counttime--;
    if(counttime == 0)
    {
        timer_count->disconnect(this);
    }

    setPlainText(QString("Time: " + QString::number(counttime)));

}
