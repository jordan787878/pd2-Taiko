#include "combo.h"
#include <QFont>
#include "game.h"

extern Game * game;

Combo::Combo(QGraphicsItem *parent) :QGraphicsTextItem(parent)
{
    setPlainText(QString("COMBO ") + QString::number(combonumber));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",15,15));


}

void Combo::comboincrease()
{
    combonumber++;

    if( combonumber >=10 && combonumber%10 == 0 ) {  game->combosound->play(); }

    if(combonumber >= 25)
    {
       setDefaultTextColor(Qt::red);
    }

    setPlainText(QString("COMBO ") + QString::number(combonumber));
    this->show();
}



void Combo::combotozero()
{
   if ( combonumber != 0){
     combonumber = 0;
     setDefaultTextColor(Qt::yellow);
     this->hide();
     game->god->play();
   }
}
