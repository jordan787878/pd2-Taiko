#ifndef COMBO_H
#define COMBO_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QDebug>

class Combo : public QGraphicsTextItem{
public:
    Combo(QGraphicsItem * parent=0);

    void comboincrease();
    void combotozero();
    int combonumber = 0;

};

#endif // COMBO_H
