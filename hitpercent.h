#ifndef HITPERCENT_H
#define HITPERCENT_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QDebug>

class Hitpercent : public QGraphicsTextItem{
public:
    Hitpercent(QGraphicsItem * parent=0);
    void sethitpercent(int & beat);
    int  gethitbeats();
    void increase();

    int hitbeat = 0;
    int hitpercent = 0;
    int allbeatnumber = 0;

};

#endif // HITPERCENT_H
