#include "startwindow.h"
#include <QPushButton>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <QMessageBox>
#include "game.h"

extern Game * game;

Startwindow::Startwindow()
{
    //set scene
    startscene = new QGraphicsScene(this);
    startscene->setSceneRect(0,0,400,300);
    setBackgroundBrush(QBrush(QPixmap(":/pic/background.jpg")));

    //set view to scene
    setScene(startscene);



    //setview
    setFixedSize(400,300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QPushButton * btn = new QPushButton("PLAY",this);
    btn->setGeometry(250,200,100,60);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(startgame()));

    QPushButton * btnexit = new QPushButton("EXIT",this);
    btnexit->setGeometry(70,200,100,60);
    connect(btnexit,SIGNAL(clicked(bool)),this,SLOT(exitgame()));

}


void Startwindow::startgame()
{
    close();
    delete this;

    game = new Game(0);
    game->show();
}

void Startwindow::exitgame()
{
    close();
    delete this;
}


