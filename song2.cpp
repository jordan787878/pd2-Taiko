#include "song2.h"
#include "game.h"
#include <stdlib.h>

extern Game * game;

Song2::Song2(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{
    song2bgm = new QMediaPlayer(this);
    song2bgm->setMedia(QUrl("qrc:/music/song2.mp3"));
    song2bgm->play();

    gameback = new QGraphicsPixmapItem(this);
    gameback->setPixmap(QPixmap(":/pic/gameback0.jpg"));
    gameback->setPos(0,175);
    game->scene->addItem(gameback);

    count = new Countdown(songtime,this);
    count->setPos(600,45);
    game->scene->addItem(count);

    timer_checktime = new QTimer(this);
    connect(timer_checktime,SIGNAL(timeout()),this,SLOT(endsong()));
    timer_checktime->start(songtime*1000);



/////
       QTimer::singleShot((1646.5/8)*2,this,SLOT(createcontbeatshort()));
       QTimer::singleShot((1646.5/8)*10,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*13,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*18,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*21,this,SLOT(createbeat1()));

       QTimer::singleShot((1646.5/8)*26,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*27.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*29,this,SLOT(createbeat1()));
       QTimer::singleShot((1638.5/8)*30.5,this,SLOT(createbeat2()));
       QTimer::singleShot((1638.5/8)*32,this,SLOT(createbeat1()));
       QTimer::singleShot((1638.5/8)*33.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1638.5/8)*35,this,SLOT(createbeat1()));

       QTimer::singleShot((1638.5/8)*42.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1638.5/8)*44,this,SLOT(createbeat2()));
       QTimer::singleShot((1638.5/8)*45.5,this,SLOT(createbeat2()));
       QTimer::singleShot((1634.5/8)*47,this,SLOT(createbeat2()));
       QTimer::singleShot((1634.5/8)*48.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1634.5/8)*50,this,SLOT(createbeat1()));
       QTimer::singleShot((1634.5/8)*51.5,this,SLOT(createbeat2()));

       QTimer::singleShot((1634.5/8)*58,this,SLOT(createbeat2()));
       QTimer::singleShot((1634.5/8)*59.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1634.5/8)*61,this,SLOT(createbeat2()));
       QTimer::singleShot((1630.5/8)*62.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1630.5/8)*64,this,SLOT(createbeat1()));
       QTimer::singleShot((1630.5/8)*65.5,this,SLOT(createbeat2()));
       QTimer::singleShot((1630.5/8)*67,this,SLOT(createbeat1()));

       QTimer::singleShot((1646.5/8)*74,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*78.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*82.5,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*86.5,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*89.5,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*91,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*95,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*99,this,SLOT(createbeat2()));
       QTimer::singleShot((1646.5/8)*103,this,SLOT(createbeat1()));
       QTimer::singleShot((1646.5/8)*105.5,this,SLOT(createbeat2()));


}
void Song2::addbeat(int type)
{

    if(type == 1)
    {
        beat1[i] = new Beat();
        beat1[i]->movesize = 1.5;
        beat1[i]->setPos(810,100);
        game->scene->addItem(beat1[i]);
        return;
    }

    if(type == 2)
    {
        beat2[j] = new Beat2();
        beat2[j]->movesize = 1.5;
        beat2[j]->setPos(810,100);
        game->scene->addItem(beat2[j]);
        return;
    }

    if (type == 3)
    {
        contbeatshort[k] = new Beatcont(1);
        contbeatshort[k]->movesize = 1.5;
        contbeatshort[k]->setPos(810,100);
        game->scene->addItem(contbeatshort[k]);
        return;
    }

//    if (type == 4)
//    {
//        contbeatlong[l] = new Beatcont(2);
//        contbeatlong[l]->movesize = 1.5;
//        contbeatlong[l]->setPos(810,100);
//        game->scene->addItem(contbeatlong[l]);
//        return;
//    }

}

void Song2::createbeat1()
{
    addbeat(1);
    i++;

}


void Song2::createbeat2()
{
    addbeat(2);
    j++;
}

void Song2::createcontbeatshort()
{
    addbeat(3);
    k++;
}




void Song2::endsong()
{
    song2bgm->stop();
    timer_checktime->disconnect();

    over = new Overwindow();
    over->overclearscore = clearscore;
    over->setseescore(game->score->getscore());

    over->statecheck = game->gamestate;
    if(game->gamestate <= state){
       over->setstate(state);
    }

    over->show();
    delete this;
    delete game;
}


