#include "song2noraml.h"
#include "game.h"
#include <stdlib.h>

extern Game * game;

Song2noraml::Song2noraml(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
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


    QTimer::singleShot(0,this,SLOT(createbeat1()));
    QTimer::singleShot(1647/2,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/2)*2,this,SLOT(createbeat2()));

    QTimer::singleShot((1647/8)*17,this,SLOT(createcontbeatshort()));
    QTimer::singleShot((1647/8)*23,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*25,this,SLOT(createcontbeatshort()));
    QTimer::singleShot((1647/8)*31,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*33,this,SLOT(createcontbeatshort()));
    QTimer::singleShot((1647/8)*39,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*41,this,SLOT(createcontbeatshort()));
    QTimer::singleShot((1647/8)*47,this,SLOT(createbeat2()));

    QTimer::singleShot((1647/8)*49,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*53,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*57,this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*61,this,SLOT(createbeat1()));

    QTimer::singleShot((1647/8)*65,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*67,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*69,this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*71,this,SLOT(createbeat1()));

    QTimer::singleShot((1647/8)*73,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*(74.5),this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*(76),this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*(77.5),this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*(79),this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*(80.5),this,SLOT(createbeat1()));

    QTimer::singleShot((1647/8)*89,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*92,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*93,this,SLOT(createbeat2()));

    QTimer::singleShot((1647/8)*94,this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*95,this,SLOT(createbeat1()));
    QTimer::singleShot((1647/8)*96,this,SLOT(createbeat1()));

    QTimer::singleShot((1647/8)*99,this,SLOT(createbeat2()));
    QTimer::singleShot((1647/8)*100,this,SLOT(createcontbeatlong()));
}

void Song2noraml::addbeat(int type)
{

    if(type == 1)
    {
        beat1[i] = new Beat();
        beat1[i]->movesize = 2;
        beat1[i]->setPos(820,100);
        game->scene->addItem(beat1[i]);
        return;
    }

    if(type == 2)
    {
        beat2[j] = new Beat2();
        beat2[j]->movesize = 2;
        beat2[j]->setPos(820,100);
        game->scene->addItem(beat2[j]);
        return;
    }

    if (type == 3)
    {
        contbeatshort[k] = new Beatcont(1);
        contbeatshort[k]->movesize = 2;
        contbeatshort[k]->setPos(820,100);
        game->scene->addItem(contbeatshort[k]);
        return;
    }

    if (type == 4)
    {
        contbeatlong[l] = new Beatcont(2);
        contbeatlong[l]->movesize = 2;
        contbeatlong[l]->setPos(820,100);
        game->scene->addItem(contbeatlong[l]);
        return;
    }

}

void Song2noraml::createbeat1()
{
    addbeat(1);
    i++;

}


void Song2noraml::createbeat2()
{
    addbeat(2);
    j++;
}

void Song2noraml::createcontbeatshort()
{
    addbeat(3);
    k++;
}

void Song2noraml::createcontbeatlong()
{
    addbeat(4);
    l++;
}


void Song2noraml::endsong()
{
    song2bgm->stop();
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
