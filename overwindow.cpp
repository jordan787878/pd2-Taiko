#include "overwindow.h"
#include <QPushButton>
#include <QImage>
#include <QFont>
#include <QTimer>
#include <QPixmap>


Overwindow::Overwindow()
{

    //set scene
    startscene = new QGraphicsScene(this);
    startscene->setSceneRect(0,0,400,300);


    //set view to scene
    setScene(startscene);

    //setview
    setFixedSize(400,300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QPushButton * btn = new QPushButton("Back To Menu",this);
    btn->setGeometry(270,250,100,30);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(startgame()));

    QPushButton * btnexit = new QPushButton("EXIT",this);
    btnexit->setGeometry(50,250,100,30);
    connect(btnexit,SIGNAL(clicked(bool)),this,SLOT(exitgame()));

    clearsound = new QMediaPlayer(this);
    clearsound->setMedia(QUrl("qrc:/music/clear.mp3"));
    clearsound->setVolume(1000000000);


    //set back graphic
    clearback = new QGraphicsPixmapItem();
    clearback->setPixmap(QPixmap(":/pic/clearpic.jpg"));

    failback = new QGraphicsPixmapItem();
    failback->setPixmap(QPixmap(":/pic/failback.jpg"));


}




//set and displayscore
void Overwindow::setseescore(int n)
{  

   QLabel * cleargame = new QLabel(this);
   cleargame->setText("<b>CLEAR</b>");
   cleargame->setFont(QFont("times",30));
   cleargame->setStyleSheet("QLabel{color:white;}");
   cleargame->setGeometry(130,180,150,80);
   cleargame->setHidden(true);

 seescore = n;

   if(seescore > overclearscore){
   cleargame->setHidden(false);
   clearsound->play();
   startscene->addItem(clearback);
   }

   else
   { startscene->addItem(failback); }

   displayscore = new QGraphicsTextItem();
   displayscore->setPlainText(QString("Score: ") + QString::number(seescore));
   displayscore->setFont(QFont("times",40,40));
   displayscore->setDefaultTextColor(Qt::white);
   displayscore->setPos(30,130);
   startscene->addItem(displayscore);

}

void Overwindow::setstate(int number)
{
  statecheck = number;
  if(seescore > overclearscore)
  {
      statecheck++;
      return;
  }


}



void Overwindow::startgame()
{
    delete displayscore;
    delete clearback;
    delete failback;
    delete this;

    game = new Game(this->statecheck);
    game->show();

}

void Overwindow::exitgame()
{
    close();
    delete this;
}
