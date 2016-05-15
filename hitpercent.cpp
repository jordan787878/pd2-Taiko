#include "hitpercent.h"
#include <QFont>
#include <QDebug>


Hitpercent::Hitpercent(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString(QString::number(hitpercent) + "%"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",30,30));
}

void Hitpercent::sethitpercent(int & beat)
{
    hitpercent = beat*100/allbeatnumber;
}

int Hitpercent::gethitbeats()
{
    return hitbeat;
}

void Hitpercent::increase()
{
    hitbeat++;
    sethitpercent(hitbeat);

    if( hitpercent >= 90) {
      setDefaultTextColor(Qt::red);
    }

    else if( hitpercent >= 65) {
      setDefaultTextColor(Qt::blue);
    }

    setPlainText(QString(QString::number(hitpercent) + "%"));
}

