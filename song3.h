#ifndef SONG3_H
#define SONG3_H


#include <QGraphicsItemGroup>
#include "beat.h"
#include "beat2.h"
#include "beatcontinuous.h"
#include "countdown.h"
#include <QPushButton>
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsVideoItem>



class Song3 : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song3(QGraphicsItem * parent = 0);
    void addbeat(int);

    QMediaPlayer * song3bgm;
    QMediaPlayer * player ;
    QGraphicsVideoItem * vw;


    Countdown * count;
    QTimer * timer_checktime;
    Overwindow * over;


  //song3 info
    const int state = 0;
    const int songtime = 30;     //    int songtime = 80;
    int beatnumber = 0;

////basic freq
    int song3freq = 666.75;

//  score
    int getscore = 0;
    const int clearscore = 80000;
    const int sumbeat = 41;


    Beat * beat1[21];
    int i = 0;
    Beat2 * beat2[20];
    int j = 0;
    Beatcont * contbeatlong[1];
    int l = 0;


public slots:
    void endsong();

    void createbeat1();
    void createbeat2();
    void createcontbeatlong();



};

#endif // SONG3_H
