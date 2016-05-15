#ifndef OVERWINDOW_H
#define OVERWINDOW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include "game.h"
#include <QMediaPlayer>

extern Game * game;

class Overwindow : public QGraphicsView{
    Q_OBJECT
public:
    Overwindow();
    void setseescore(int);
    void setstate(int);

    QGraphicsScene * startscene;
    QMediaPlayer * clearsound;
    QGraphicsPixmapItem * clearback ;
    QGraphicsPixmapItem * failback;
    QGraphicsTextItem * displayscore;
    int  seescore = 0;
    int overclearscore = 0;

    int statecheck = 0;




public slots:
    void startgame();
    void exitgame();
};

#endif // OVERWINDOW_H
