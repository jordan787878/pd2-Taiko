#ifndef SONG1NORMAL_H
#define SONG1NORMAL_H

#include <QGraphicsItemGroup>
#include "beat.h"
#include "beat2.h"
#include "countdown.h"
#include <QPushButton>
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>

class Song1normal : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song1normal(QGraphicsItem * parent = 0);
    void CreateBeats(int);

    QMediaPlayer * song1bgm;
    Countdown * count;
    QTimer * timer_beat;
    QTimer * timer_checktime;
    Overwindow * over;
    QGraphicsPixmapItem * gameback;


  //song1 info
    const int state = 1;

    int beatnumber = 0;
    int maxbeat = 70;
    double song1freq = 1181.25/2.5;
    const int songtime = 40;
//  basizstepvelocity = 0.08*2.5/ms
//  basicfrequency = 1181.25/2.5 ms
//  basicdistance  = 94.5 pix

    double steppos[3] = {847.25,823.625,800};

//  score
    int getscore = 0;
    const int clearscore = 80000;
    const int sumbeat = 70;

public slots:
    void SpawnBeats();
    void endsong();

};
#endif // SONG1NORMAL_H
