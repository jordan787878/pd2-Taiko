#include "beat.h"
#include <QPixmap>
#include <QList>
#include <QDebug>
#include "game.h"
#include <stdlib.h>

extern Game *game;

Beat::Beat(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
   //set beat graphic
   setPixmap(QPixmap(":/pic/beat.png"));

   timer_beat_move = new QTimer(this);
   connect(timer_beat_move,SIGNAL(timeout()),this,SLOT(move()));
   timer_beat_move->start(12.5);

}



void Beat::move()
{
   setPos(x()-movesize,y());

   if(this->pos().rx() <= 0)
   {
      timer_beat_move->disconnect();
      game->scene->removeItem(this);
      qDebug() << "destruct beat";
      delete this;
      return;
   }
}




