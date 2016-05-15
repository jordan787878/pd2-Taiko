#ifndef SONG1DEVIL_H
#define SONG1DEVIL_H

#include "beat.h"
#include "beat2.h"
#include "countdown.h"
#include <QPushButton>
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>

class Song1devil : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song1devil(QGraphicsItem * parent = 0);
    void CreateBeats(int);

    QMediaPlayer * song1bgm;
    Countdown * count;
    QTimer * timer_beat;
    QTimer * timer_checktime;
    Overwindow * over;
    QGraphicsPixmapItem * gameback;


  //song1 info
    int state = 2;

    int beatnumber = 0;
    int maxbeat = 110;
    double song1freq = 1181.25/3;
    int songtime = 50;
//  basizstepvelocity = 0.08*3/ms
//  basicfrequency = 1181.25/3 ms
//  basicdistance  = 94.5 pix

    double steppos[4] = {856.7,837.8,818.9,800};  //{847.25,823.625,800};  {875.6,856.7,837.8,818.9,800};
                                                       //{878.5,863,831.5,815.75,800};
//  score
    int getscore = 0;
    int clearscore = 280000;
    int sumbeat = 110;

public slots:
    void SpawnBeats();
    void endsong();

};

#endif // SONG1DEVIL_H
