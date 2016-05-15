#include "game.h"
#include "beat.h"
#include "beat2.h"
#include <QDebug>
#include <stdlib.h>
#include <QPixmap>
#include "overwindow.h"
#include <QFont>
#include <QGraphicsLineItem>
#include <QPen>
#include "song1.h"
#include "song1normal.h"
#include "song1devil.h"
#include "song2.h"
#include "song2noraml.h"
#include "song3.h"
#include <QBrush>


Game::Game(const int number)
{
    qDebug() << "create game";
    gamestate = number;

    //create scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QPixmap(":/pic/gameback.jpg")));


    //set view to scene
    setScene(scene);


    //set view size
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create drum
    drum = new Drum();
    drum->setPos(100,100);
    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    drum->setFocus();

    //add percent
    percent = new Hitpercent();
    percent->setPos(360,15);



    //set game bgm && hit sound
    gamebgm = new QMediaPlayer(this);
    gamebgm->setMedia(QUrl("qrc:/music/gamebgm.mp3"));
    gamebgm->play();
    connect(gamebgm,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(repeatsong()));

    Fbeat = new QMediaPlayer(this);
    Fbeat->setMedia(QUrl("qrc:/music/Fbeat.wav"));
    Jbeat = new QMediaPlayer(this);
    Jbeat->setMedia(QUrl("qrc:/music/Jbeat.wav"));
    combosound = new QMediaPlayer(this);
    combosound->setMedia(QUrl("qrc:/music/combo.mp3"));
    combosound->setVolume(70);
    god = new QMediaPlayer(this);
    god->setMedia(QUrl("qrc:/music/god.mp3"));
    god->setVolume(70);
    contibeatsound = new QMediaPlayer(this);
    contibeatsound->setMedia(QUrl("qrc:/music/contibeat.mp3"));
    contibeatsound->setVolume(1000000000);




    //set score
    score = new Score();
    score->setPos(600,15);
    scene->addItem(score);
    score->hide();


    //set hit & nice
    hit = new QLabel(this);
    hit->setText("<b>H I T~</b>");
    hit->setStyleSheet("QLabel{color:black;}");
    hit->setGeometry(105,60,40,30);
    hit->setHidden(true);

    nicehit = new QLabel(this);
    nicehit->setPixmap(QPixmap(":/pic/Nice.png"));
    nicehit->setGeometry(95,55,60,30);
    nicehit->setHidden(true);

    showconthit = new QGraphicsTextItem();
    showconthit->setPlainText(QString(QString::number(contihit)+"Hit"));
    showconthit->setDefaultTextColor(Qt::blue);
    showconthit->setFont(QFont("times",20,20));
    showconthit->setPos(20,50);
    showconthit->hide();


    newstate = new QLabel(this);
    newstate ->setText("<b>N E W  !</b>");
    newstate->setFont(QFont("times",10,10));
    newstate->setStyleSheet("QLabel{color:white;}");
    newstate ->hide();



    //set label for game help
    gamehelp = new QLabel(this);
    gamehelp->setText("Press J hits red beat (right  hand)\nPress F hits blue beat (left  hand)");
    gamehelp->setFont(QFont("times",15));
    gamehelp->setStyleSheet("QLabel{color:white;}");
    gamehelp->setGeometry(250,15,350,50);
    gamehelp->setHidden(false);

    //add combo system
    combo = new Combo();
    combo->setPos(10,30);
    scene->addItem(combo);
    combo->hide();


       //add path
    QPointF pt1(0,125); QPointF pt2(800,125);
    QLineF line(pt1,pt2);
    road = new QGraphicsLineItem(line);
    QPen pen;
    pen.setWidth(80);
    pen.setColor(Qt::gray);
    road->setPen(pen);


////SONG 1

    //create song1 button
    song1btn = new QPushButton(this);
    song1btn->setText("Sun of Descendent\n(easy)");
    song1btn->setGeometry(150,120,100,100);
    connect(song1btn,SIGNAL(clicked(bool)),this,SLOT(song1play()));


    song1normalbtn = new QPushButton(this);
    song1normalbtn->setText("Descendent of Sun\n(normal)");
    song1normalbtn->setGeometry(150,270,100,100);
    connect(song1normalbtn,SIGNAL(clicked(bool)),this,SLOT(song1normalplay()));
    song1normalbtn->hide();
    if(gamestate >= 1) {
      newstate->setGeometry(180,355,50,50);
      newstate->show();
      song1normalbtn->show();
    }

    song1devilbtn = new QPushButton(this);
    song1devilbtn->setText("Sun of Descendent\n(devil)");
    song1devilbtn->setGeometry(150,420,100,100);
    connect(song1devilbtn,SIGNAL(clicked(bool)),this,SLOT(song1devilplay()));
    song1devilbtn->hide();
    if(gamestate >= 2) {
      newstate->setGeometry(180,505,50,50);
      newstate->show();
      song1devilbtn->show();
    }



////SONG 2

    //create song2 button
    song2btn = new QPushButton(this);
    song2btn->setText("Moster Hunter\n(easy)");
    song2btn->setGeometry(345,120,100,100);
    connect(song2btn,SIGNAL(clicked(bool)),this,SLOT(song2play()));

    song2normalbtn = new QPushButton(this);
    song2normalbtn->setText("Monster Hunter\n(normal)");
    song2normalbtn->setGeometry(345,270,100,100);
    connect(song2normalbtn,SIGNAL(clicked(bool)),this,SLOT(song2normalplay()));
    song2normalbtn->hide();
    if(gamestate >= 1) {
      newstate->setGeometry(375,355,50,50);
      newstate->show();
      song2normalbtn->show();
    }



////SONG 3

    //create song3 button
    song3btn = new QPushButton(this);
    song3btn->setText("Attack on Titan\n(easy)");
    song3btn->setGeometry(550,120,100,100);
    connect(song3btn,SIGNAL(clicked(bool)),this,SLOT(song3play()));




}

void Game::mousePressEvent(QMouseEvent *event)
{
   event->ignore();
}

void Game::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->ignore();
}

void Game::repeatsong()
{
    gamebgm->setPosition(0);
    gamebgm->play();
}



void Game::contiincrease()
{
    contihit++;
    if(contihit == 1 ) { contibeatsound->play(); }
    score->scoreincrease(contihit*50);
    combo->comboincrease();
    showconthit->setPlainText(QString(QString::number(contihit)+"Hit"));
    showconthit->show();
}

void Game::hidemenu()
{

    setBackgroundBrush(Qt::white);
    gamebgm->disconnect();
    gamebgm->stop();
    gamehelp->hide();
    song1btn->hide();
    song1normalbtn->hide();
    song1devilbtn->hide();
    song2btn->hide();
    song2normalbtn->hide();
    song3btn->hide();
    newstate->hide();
    scene->addItem(road);
    scene->addItem(drum);
    scene->addItem(showconthit);
}


////SONG 1

void Game::song1play()
{
    hidemenu();

    Song1 * song1 = new Song1();
    percent->allbeatnumber = song1->sumbeat;
    scene->addItem(percent);
    scene->addItem(song1);
    score->show();
}

void Game::song1normalplay()
{
    hidemenu();

    Song1normal * song1normal = new Song1normal();
    percent->allbeatnumber = song1normal->sumbeat;
    scene->addItem(percent);
    scene->addItem(song1normal);
    score->show();
}

void Game::song1devilplay()
{
    hidemenu();

    Song1devil * song1devil = new Song1devil();
    percent->allbeatnumber = song1devil->sumbeat;
    scene->addItem(percent);
    scene->addItem(song1devil);
    score->show();

}



////SONG 2

void Game::song2play()
{
    hidemenu();

    Song2 * song2 = new Song2();
    percent->allbeatnumber = song2->sumbeat;
    scene->addItem(percent);
    scene->addItem(song2);
    score->show();

}

void Game::song2normalplay()
{
    hidemenu();

    Song2noraml * song2normal = new Song2noraml();
    percent->allbeatnumber = song2normal->sumbeat;
    scene->addItem(percent);
    scene->addItem(song2normal);
    score->show();


}

////SONG 3

void Game::song3play()
{
    hidemenu();

    Song3 * song3 = new Song3();
    percent->allbeatnumber = song3->sumbeat;
    scene->addItem(percent);
    scene->addItem(song3);
    score->show();
}




