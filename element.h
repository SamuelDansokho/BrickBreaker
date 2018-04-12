#ifndef ELEMENT_H
#define ELEMENT_H

#include <GL/glu.h>
class Brick;
class Wall;
class Ball;
class Plate;

class Element
{
public:
    Element();
    virtual ~Element();
    virtual void Display(Element const& e);
    virtual void Update(Element const& e);
    float posX_;
    float posY_;
    GLUquadric *quadrique;
    virtual float getPosX();
    virtual float getPosY();

};

#endif // ELEMENT_H
