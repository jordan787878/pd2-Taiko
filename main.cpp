#include <QApplication>
#include "startwindow.h"
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Startwindow * start = new Startwindow();
    start->show();



    return a.exec();
}
