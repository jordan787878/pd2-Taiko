#include "drum.h"
#include<QPixmap>
#include <QDebug>
#include "game.h"
#include "beat.h"
#include "beat2.h"
#include "beatcontinuous.h"
#include <typeinfo>
#include <QLineF>

extern Game * game;

Drum::Drum(QGraphicsItem * parent) : QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/pic/drum.png"));
}

void Drum::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_F)
    {
       //play drum sound
       if(game->Fbeat->state() == QMediaPlayer::PlayingState){
           game->Fbeat->setPosition(0);
       }

       else if(game->Fbeat->state() == QMediaPlayer::StoppedState){
           game->Fbeat->play();
       }


        //if hit the key and collide with beats
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i=0,n=colliding_items.size();i<n;i++)
        {
            if(typeid(*(colliding_items[i])) == typeid(Beatcont))
            {
               game->contiincrease();
               return;
            }

            if(typeid(*(colliding_items[i])) == typeid(Beat))
            {
                QPointF point_drum = game->drum->pos();
                QPointF point_beat = colliding_items[i]->pos();
                QLineF line(point_drum,point_beat);

                //normal hit,score +100
                if(line.length() < 15)
                {
                    // good hit,score +500
                    if(line.length() < 4.5)
                    {
                      //show nice
                      game->nicehit->setHidden(false);
                      QTimer::singleShot(120,game->nicehit,SLOT(hide()));

                      game->combo->comboincrease();

                      //remove beats
                      scene()->removeItem(colliding_items[i]);
                      delete colliding_items[i];
                      game->score->scoreincrease(500*(1+(game->combo->combonumber-1)*0.2));
                      game->percent->increase();
                      return;

                    }
                  //show hit
                  game->hit->setHidden(false);
                  QTimer::singleShot(150,game->hit,SLOT(hide()));

                  game->combo->comboincrease();

                  //remove beats
                  scene()->removeItem(colliding_items[i]);
                  delete colliding_items[i];
                  game->score->scoreincrease(100*(1+(game->combo->combonumber-1)*0.2));
                  game->percent->increase();
                  return;
                }


            }

        }

       game->combo->combotozero();
    }

    if(event->key() == Qt::Key_J)
    {
        //play drum sound
        if(game->Jbeat->state() == QMediaPlayer::PlayingState){
            game->Jbeat->setPosition(0);
        }

        else if(game->Jbeat->state() == QMediaPlayer::StoppedState){
            game->Jbeat->play();
        }


         //if hit the key and collide with beats
         QList<QGraphicsItem *> colliding_items = collidingItems();
         for (int i=0,n=colliding_items.size();i<n;i++)
         {
             if(typeid(*(colliding_items[i])) == typeid(Beatcont))
             {
                 game->contiincrease();
                 return;
             }

             if(typeid(*(colliding_items[i])) == typeid(Beat2))
             {
                 QPointF point_drum = game->drum->pos();
                 QPointF point_beat = colliding_items[i]->pos();
                 QLineF line(point_drum,point_beat);

                 //normal hit,score + 100
                 if(line.length() < 15)
                 {
                     //good hit,score + 500
                     if(line.length() < 4.5)
                     {


                       //show nice
                       game->nicehit->setHidden(false);
                       QTimer::singleShot(150,game->nicehit,SLOT(hide()));

                       game->combo->comboincrease();

                       //remove beats
                       scene()->removeItem(colliding_items[i]);
                       delete colliding_items[i];
                       game->score->scoreincrease(500*(1+(game->combo->combonumber-1)*0.2));
                       game->percent->increase();
                       return;
                     }

                   //show hit
                   game->hit->setHidden(false);
                   QTimer::singleShot(120,game->hit,SLOT(hide()));

                   game->combo->comboincrease();


                   //remove beats
                   scene()->removeItem(colliding_items[i]);
                   delete colliding_items[i];
                   game->score->scoreincrease(100*(1+(game->combo->combonumber-1)*0.2));
                   game->percent->increase();
                   return;
                 }


              }

         }

        game->combo->combotozero();

    }

}






