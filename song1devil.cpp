#include "song1devil.h"
#include "game.h"
#include <stdlib.h>

extern Game * game;

Song1devil::Song1devil(QGraphicsItem *parent) : QGraphicsItemGroup(parent)
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

    CreateBeats(maxbeat);

    timer_checktime = new QTimer(this);
    connect(timer_checktime,SIGNAL(timeout()),this,SLOT(endsong()));
    timer_checktime->start(songtime*1000);

    over = new Overwindow();

}

void Song1devil::CreateBeats(int number)
{
  maxbeat = number;
  timer_beat = new QTimer(this);
  connect(timer_beat,SIGNAL(timeout()),this,SLOT(SpawnBeats()));
  timer_beat->start(song1freq);

}

void Song1devil::SpawnBeats()
{
  int type_beat = 0+rand()%2;
  int steptype = 0 +rand()%4;

  if(type_beat == 0){
  Beat * beat = new Beat();
  beat->setPos(steppos[steptype],100);
  beat->movesize = 3;
  game->scene->addItem(beat);
  }

  if(type_beat == 1){
  Beat2 * beat2 = new Beat2();
  beat2->setPos(steppos[steptype],100);
  beat2->movesize = 3;
  game->scene->addItem(beat2);
  }

  beatnumber++;
  if( beatnumber >= maxbeat)
  {
      timer_beat->disconnect();
      return;
  }

}

void Song1devil::endsong()
{
    song1bgm->stop();
    timer_beat->disconnect();
    timer_checktime->disconnect();

    over->overclearscore = clearscore;
    over->setseescore(game->score->getscore());

    over->statecheck = game->gamestate;
    if(game->gamestate <=state){
       over->setstate(state);
    }

    over->show();

    delete this;
    delete game;
}
