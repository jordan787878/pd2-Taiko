#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QPointF>
#include <QDebug>

class Drum : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drum(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);


public slots:


};

#endif // DRUM_H
