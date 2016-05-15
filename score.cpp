#include "score.h"
#include <QFont>
#include <QDebug>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //set health
    score = 0;

    setPlainText(QString("Score: " + QString::number(score)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",20,20));
}

void Score::scoreincrease(const int number)
{
   score += number;
   setPlainText(QString("Score: " + QString::number(score)));
}



int Score::getscore()
{
    return score;
}
