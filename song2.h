#ifndef SONG2_H
#define SONG2_H

#include <QGraphicsItemGroup>
#include "beat.h"
#include "beat2.h"
#include "beatcontinuous.h"
#include "countdown.h"
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>
#include <QList>

class Song2 : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song2(QGraphicsItem * parent = 0);
    void addbeat(int);

    QMediaPlayer * song2bgm;
    Countdown * count;
    QTimer * timer_checktime;
    Overwindow * over;
    QGraphicsPixmapItem * gameback;



  //song2 info
    const int state = 0;
    const int songtime = 30;
    int beatnumber = 0;

////basic freq
    int song2freq = 1647;

//  score
    int getscore = 0;
    const int clearscore = 50000;
    const int sumbeat = 35;

    Beat * beat1[18];
    int i = 0;
    Beat2 * beat2[17];
    int j = 0;
    Beatcont * contbeatshort[1];
    int k = 0;



public slots:
    void endsong ();

    void createbeat1();
    void createbeat2();
    void createcontbeatshort();


};

#endif // SONG2_H
