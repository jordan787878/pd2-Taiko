#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include <QGraphicsTextItem>
#include <QTimer>
#include <QGraphicsItem>
#include <QObject>
#include <QDebug>

class Countdown :public QGraphicsTextItem{
    Q_OBJECT
public:
    Countdown(const int n,QGraphicsItem * parent=0);
    int counttime;
    QTimer * timer_count;

public slots:
    void timedecrease();
};

#endif // COUNTDOWN_H
