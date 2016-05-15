#include "song3.h"
#include "game.h"
#include <stdlib.h>
#include <QGraphicsVideoItem>

extern Game * game;

Song3::Song3(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{
    //add back mv
    player = new QMediaPlayer(this);
    vw = new QGraphicsVideoItem(this);
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Qt/pd2-Taiko/song3mv.mp4"));
    vw->setSize(QSizeF(800,600-165));
    vw->setPos(0,165);
    game->scene->addItem(vw);
    player->setVolume(0);
    player->play();


    //add count time
    count = new Countdown(songtime,this);
    count->setPos(600,45);
    game->scene->addItem(count);

    timer_checktime = new QTimer(this);
    connect(timer_checktime,SIGNAL(timeout()),this,SLOT(endsong()));
    timer_checktime->start(songtime*1000);

    over = new Overwindow();

    //set song
    song3bgm = new QMediaPlayer(this);
    song3bgm->setMedia(QUrl("qrc:/music/bgm2.1.mp3"));
    song3bgm->play();


/////1-8 拍

    QTimer::singleShot(0,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*1.9,this,SLOT(createbeat2()));

    QTimer::singleShot((666.75/2)*4,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*6,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*8,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*10,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*12,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*14,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*16,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*18,this,SLOT(createbeat1()));

    QTimer::singleShot((666.75/2)*20,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*22,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*24,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*26,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*28,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*30,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*32,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*33,this,SLOT(createcontbeatlong()));


    QTimer::singleShot((666.75/2)*39,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*40,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*40.5,this,SLOT(createbeat2()));

    QTimer::singleShot((666.75/2)*41.5,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*42.5,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*43.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*44.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*45.5,this,SLOT(createbeat2()));


    QTimer::singleShot((666.75/2)*47,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*48,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*48.5,this,SLOT(createbeat2()));

    QTimer::singleShot((666.75/2)*49.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*50.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*51.5,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*52.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*53.5,this,SLOT(createbeat1()));


    QTimer::singleShot((666.75/2)*55,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*56,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*56.5,this,SLOT(createbeat1()));

    QTimer::singleShot((666.75/2)*57.5,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*58.5,this,SLOT(createbeat2()));


    QTimer::singleShot((666.75/2)*63,this,SLOT(createbeat1()));
    QTimer::singleShot((666.75/2)*66,this,SLOT(createbeat2()));
    QTimer::singleShot((666.75/2)*68,this,SLOT(createbeat2()));

}


void Song3::addbeat(int type)
{

    if(type == 1)
    {
        beat1[i] = new Beat();
        beat1[i]->movesize = 2.5;
        beat1[i]->setPos(800,100);
        game->scene->addItem(beat1[i]);
        return;
    }

    if(type == 2)
    {
        beat2[j] = new Beat2();
        beat2[j]->movesize = 2.5;
        beat2[j]->setPos(800,100);
        game->scene->addItem(beat2[j]);
        return;
    }

//    if (type == 3)
//    {
//        contbeatshort[k] = new Beatcont(1);
//        contbeatshort[k]->movesize = 2.5;
//        contbeatshort[k]->setPos(800,100);
//        game->scene->addItem(contbeatshort[k]);
//        return;
//    }

    if (type == 4)
    {
        contbeatlong[l] = new Beatcont(2);
        contbeatlong[l]->movesize = 2.5;
        contbeatlong[l]->setPos(800,100);
        game->scene->addItem(contbeatlong[l]);
        return;
    }

}

void Song3::createbeat1()
{
    addbeat(1);
    i++;

}


void Song3::createbeat2()
{
    addbeat(2);
    j++;
}


void Song3::createcontbeatlong()
{
    addbeat(4);
    l++;
}



void Song3::endsong()
{
    player->stop();
    song3bgm->stop();
    timer_checktime->disconnect();

    over->overclearscore = clearscore;
    over->setseescore(game->score->getscore());
    over->statecheck = game->gamestate;

    over->statecheck = game->gamestate;
    if(game->gamestate <= state){
       over->setstate(state);
    }

    over->show();

    delete this;
    delete game;
}





