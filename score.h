#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QDebug>

class Score : public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void scoreincrease(const int);
    int getscore();

    int score;


};

#endif // SCORE_H
