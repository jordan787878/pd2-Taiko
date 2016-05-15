#ifndef BEATCONTINUOUS_H
#define BEATCONTINUOUS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>

class Beatcont : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Beatcont(int type,QGraphicsItem * parent=0);
    QTimer * timer_beat_move;
    float movesize = 0;
    int hidedistance = 0;


public slots:
    virtual void move();

};



#endif // BEATCONTINUOUS_H
