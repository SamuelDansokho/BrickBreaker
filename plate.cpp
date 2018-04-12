#include "plate.h"
#include <GL/glu.h>


Plate::Plate(float posX, float posY,int size):Element()
{
    posX_=posX;
    posY_=posY;
    size_=size;

}

float Plate::getPosX(){
    return this->posX_;
}
float Plate::getPosY(){
    return this->posY_;
}

void Plate::setPosX(float posX){

    this->posX_=posX;
}

void Plate::setPosY(float posY){
    this->posY_=posY;
}

void Plate::Display(){

    glPushMatrix();

    //Dessin de la brique
    glBegin(GL_QUADS);

    glColor3ub(255,0,0);
    //face arrière
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,-2.0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,-2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,-2.0);
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,-2.0);

    //face avant
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,+2.0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,+2.0);

    //face gauche
    glColor3ub(180,0,0);
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,-2.0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,-2.0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,+2.0);

    //face droite
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,-2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,-2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,+2.0);

    //face supérieure
    glColor3ub(180,255,0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,-2.0);
    glVertex3f(getPosX()-this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()+0.25,-2.0);


    glColor3ub(180,0,0);
    //face inférieure
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,-2.0);
    glVertex3f(getPosX()-this->size_,getPosY()-0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,+2.0);
    glVertex3f(getPosX()+this->size_,getPosY()-0.25,-2.0);
    glEnd();
    
    glPopMatrix();
    
}


 Plate::~Plate(){

}
