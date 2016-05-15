#ifndef SONG1_H
#define SONG1_H
#include <QGraphicsItemGroup>
#include "beat.h"
#include "beat2.h"
#include "countdown.h"
#include <QPushButton>
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>
#include "beatcontinuous.h"


class Song1 : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song1(QGraphicsItem * parent = 0);
    void addbeat(int);


//  memeber data
    QMediaPlayer * song1bgm;
    Countdown * count;
    QTimer * timer_checktime;
    QGraphicsPixmapItem * gameback;


  //song1 info
    const int state = 0;

    int beatnumber = 0;
    double song1freq = 1181.25;
    int songtime = 30;

//  basizstepvelocity = 0.08/ms
//  basicfrequency = 1181.25 ms
//  basicdistance  = 94.5 pix



//  score
    int getscore = 0;
    const int clearscore = 40000;
    const int sumbeat = 34;

    Beat * beat1[16];
    int i = 0;
    Beat2 * beat2[18];
    int j = 0;
    Beatcont * contbeatshort[1];
    int k = 0;


public slots:
    void endsong();

    void createbeat1();
    void createbeat2();
    void createcontbeatshort();

};


#endif // SONG1_H
