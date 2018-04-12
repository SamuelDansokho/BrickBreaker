
#include "brick.h"

Brick::Brick(float posX, float posY):Element()
{

    posX_=posX;
    posY_=posY;
   // state_=state;


}


void Brick::Display(){

    glPushMatrix();

    //Dessin de la brique
    glBegin(GL_QUADS);

    glColor3ub(255,255,0);
    //face arrière
    glVertex3f(getPosX()-4,getPosY()-1,-2.0);
    glVertex3f(getPosX()-4,getPosY()+1,-2.0);
    glVertex3f(getPosX()+4,getPosY()+1,-2.0);
    glVertex3f(getPosX()+4,getPosY()-1,-2.0);

    //face avant
    glVertex3f(getPosX()-4,getPosY()-1,+2.0);
    glVertex3f(getPosX()-4,getPosY()+1,+2.0);
    glVertex3f(getPosX()+4,getPosY()+1,+2.0);
    glVertex3f(getPosX()+4,getPosY()-1,+2.0);

    //face gauche
    glColor3ub(255,180,150);
    glVertex3f(getPosX()-4,getPosY()-1,-2.0);
    glVertex3f(getPosX()-4,getPosY()+1,-2.0);
    glVertex3f(getPosX()-4,getPosY()+1,+2.0);
    glVertex3f(getPosX()-4,getPosY()-1,+2.0);

    //face droite
    glVertex3f(getPosX()+4,getPosY()-1,-2.0);
    glVertex3f(getPosX()+4,getPosY()+1,-2.0);
    glVertex3f(getPosX()+4,getPosY()+1,+2.0);
    glVertex3f(getPosX()+4,getPosY()-1,+2.0);

    //face supérieure
    glColor3ub(180,180,0);
    glVertex3f(getPosX()-4,getPosY()+1,-2.0);
    glVertex3f(getPosX()-4,getPosY()+1,+2.0);
    glVertex3f(getPosX()+4,getPosY()+1,+2.0);
    glVertex3f(getPosX()+4,getPosY()+1,-2.0);

    glColor3ub(255,180,0);
    //face inférieure
    glVertex3f(getPosX()-4,getPosY()-1,-2.0);
    glVertex3f(getPosX()-4,getPosY()-1,+2.0);
    glVertex3f(getPosX()+4,getPosY()-1,+2.0);
    glVertex3f(getPosX()+4,getPosY()-1,-2.0);
    glEnd();
    
    glPopMatrix();


}

float Brick::getPosX(){

    return this->posX_;


}

float Brick::getPosY(){

    return this->posY_;

}

void Brick::setState(){

}

//QString Brick::getType(){

//    return this->type_;
//}

Brick::~Brick(){

}
