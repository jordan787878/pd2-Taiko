#ifndef BEAT_H
#define BEAT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Beat : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Beat(QGraphicsItem * parent=0);
    QTimer * timer_beat_move;

    float movesize = 0;

public slots:
    void move();


};

#endif // BEAT_H
