#include "song1.h"
#include "game.h"
#include <stdlib.h>

extern Game * game;

Song1::Song1(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{

    song1bgm = new QMediaPlayer(this);
    song1bgm->setMedia(QUrl("qrc:/music/bgm.mp3"));
    song1bgm->play();

    gameback = new QGraphicsPixmapItem(this);
    gameback->setPixmap(QPixmap(":/pic/gameback1.jpg"));
    gameback->setPos(0,175);
    game->scene->addItem(gameback);

    count = new Countdown(songtime,this);
    count->setPos(600,45);
    game->scene->addItem(count);


    timer_checktime = new QTimer(this);
    connect(timer_checktime,SIGNAL(timeout()),this,SLOT(endsong()));
    timer_checktime->start(songtime*1000);

    QTimer::singleShot((1181.25/8)*2,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*10,this,SLOT(createbeat2()));

    QTimer::singleShot((1181.25/8)*14,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*18,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*22,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*26,this,SLOT(createbeat1()));

    QTimer::singleShot((1181.25/8)*34,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*42,this,SLOT(createbeat1()));

    QTimer::singleShot((1181.25/8)*46,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*50,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*54,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*58,this,SLOT(createbeat2()));

    QTimer::singleShot((1181.25/8)*66,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*70,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*74,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*75,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*78,this,SLOT(createcontbeatshort()));

    QTimer::singleShot((1181.25/8)*94,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*97,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*98,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*101,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*102,this,SLOT(createbeat2()));

    QTimer::singleShot((1181.25/8)*110,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*113,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*114,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*117,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*118,this,SLOT(createbeat1()));

    QTimer::singleShot((1181.25/8)*124,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*126,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*128,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*130,this,SLOT(createbeat2()));

    QTimer::singleShot((1181.25/8)*133,this,SLOT(createbeat1()));
    QTimer::singleShot((1181.25/8)*136,this,SLOT(createbeat2()));
    QTimer::singleShot((1181.25/8)*140,this,SLOT(createbeat2()));

    QTimer::singleShot((1181.25/8)*148,this,SLOT(createbeat2()));


}


void Song1::addbeat(int type)
{

    if(type == 1)
    {
        beat1[i] = new Beat();
        beat1[i]->movesize = 2;
        beat1[i]->setPos(800,100);
        game->scene->addItem(beat1[i]);
        return;
    }

    if(type == 2)
    {
        beat2[j] = new Beat2();
        beat2[j]->movesize = 2;
        beat2[j]->setPos(800,100);
        game->scene->addItem(beat2[j]);
        return;
    }

    if (type == 3)
    {
        contbeatshort[k] = new Beatcont(1);
        contbeatshort[k]->movesize = 2;
        contbeatshort[k]->setPos(800,100);
        game->scene->addItem(contbeatshort[k]);
        return;
    }

//    if (type == 4)
//    {
//        contbeatlong[l] = new Beatcont(2);
//        contbeatlong[l]->movesize = 2;
//        contbeatlong[l]->setPos(800,100);
//        game->scene->addItem(contbeatlong[l]);
//        return;
//    }

}

void Song1::createbeat1()
{
    addbeat(1);
    i++;

}


void Song1::createbeat2()
{
    addbeat(2);
    j++;
}

void Song1::createcontbeatshort()
{
    addbeat(3);
    k++;
}


void Song1::endsong()
{
    song1bgm->stop();
    timer_checktime->disconnect();

    Overwindow * over = new Overwindow();
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



