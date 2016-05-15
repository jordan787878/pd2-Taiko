#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>




class Startwindow : public QGraphicsView{
    Q_OBJECT
public:
    Startwindow();
    QGraphicsScene * startscene;


public slots:
    void startgame();
    void exitgame();
};


#endif // STARTWINDOW_H
