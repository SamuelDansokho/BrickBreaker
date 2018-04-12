#include "element.h"


Element::Element():posX_(0.0),posY_(0.0)
{

    quadrique=gluNewQuadric();
}

Element::~Element(){

    gluDeleteQuadric(quadrique);

}

float Element::getPosX(){

}

float  Element::getPosY(){

}

void Element::Display(Element const& e){

//    e.Display();
}

void Element::Update(Element const& e){

//    e.Update();
}
