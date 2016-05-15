#ifndef SONG2NORAML_H
#define SONG2NORAML_H

#include <QGraphicsItemGroup>
#include "beat.h"
#include "beat2.h"
#include "beatcontinuous.h"
#include "countdown.h"
#include <QMediaPlayer>
#include <QObject>
#include "overwindow.h"
#include <QGraphicsPixmapItem>


class Song2noraml : public QObject,public QGraphicsItemGroup{
   Q_OBJECT
public:
    Song2noraml(QGraphicsItem * parent = 0);
    void addbeat(int);

    QMediaPlayer * song2bgm;
    Countdown * count;
    QTimer * timer_checktime;
    Overwindow * over;
    QGraphicsPixmapItem * gameback;

  //song2 info
    const int state = 1;
    const int songtime = 30;
    int beatnumber = 0;
    int maxbeat = 0;

////basic freq
    int song2freq = 1647;

//  score
    int getscore = 0;
    const int clearscore = 150000;
    const int sumbeat = 28;

    Beat * beat1[11];
    int i = 0;
    Beat2 * beat2[17];
    int j = 0;
    Beatcont * contbeatshort[4];
    int k = 0;
    Beatcont * contbeatlong[1];
    int l = 0;


public slots:
    void endsong();
    void createbeat1();
    void createbeat2();
    void createcontbeatshort();
    void createcontbeatlong();




};

#endif // SONG2NORAML_H
