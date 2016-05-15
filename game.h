#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "drum.h"
#include "score.h"
#include "combo.h"
#include <QTimer>
#include <QMediaPlayer>
#include<QLabel>
#include<QPushButton>
#include <QMouseEvent>
#include "hitpercent.h"
#include <QGraphicsVideoItem>


class Game : public QGraphicsView{
    Q_OBJECT

public:
    Game(const int number);                          //int for game state

    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);

    //member data
    int gamestate = 0;
    QGraphicsScene * scene;
    Drum * drum;
    Hitpercent * percent;


    QMediaPlayer * gamebgm;
    QMediaPlayer * Fbeat;
    QMediaPlayer * Jbeat;
    QMediaPlayer * combosound;
    QMediaPlayer * god;
    QMediaPlayer * contibeatsound;

    Score * score;
    QLabel * hit;
    QLabel * nicehit;
    QLabel * countdown;
    QLabel * gamehelp;

    QGraphicsTextItem * showconthit;
    int contihit = 0;
    void contiincrease();

    QLabel * newstate;
    Combo * combo;
    QGraphicsLineItem * road;

    void hidemenu();


////song 1
    QPushButton * song1btn;
    QPushButton * song1normalbtn;
    QPushButton * song1devilbtn;


////song 2
    QPushButton * song2btn;
    QPushButton * song2normalbtn;

////song 3
    QPushButton * song3btn;


public slots:
     void repeatsong();

     void song1play();
     void song1normalplay();
     void song1devilplay();


     void song2play();
     void song2normalplay();

     void song3play();


};

#endif // GAME_H
