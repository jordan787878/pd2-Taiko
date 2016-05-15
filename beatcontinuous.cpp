#include "beatcontinuous.h"
#include <QPixmap>
#include <QDebug>
#include "game.h"

extern Game *game;


Beatcont::Beatcont(int type, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{    
   //set beat graphic
   if (type == 1)
   { setPixmap(QPixmap(":/pic/beatconti.png")); hidedistance = 200;}

   if(type == 2)
   {  setPixmap(QPixmap(":/pic/beatconti2.png")); hidedistance = 400;}

   timer_beat_move = new QTimer(this);
   connect(timer_beat_move,SIGNAL(timeout()),this,SLOT(move()));
   timer_beat_move->start(12.5);

}



void Beatcont::move()
{
   setPos(x()-movesize,y());

   if(this->pos().rx() +hidedistance <= 0)
   {
      timer_beat_move->disconnect();
      game->scene->removeItem(this);
      game->contihit = 0;
      game->showconthit->hide();
      qDebug() << "destruct contibeat";
      delete this;
      return;
   }
}



