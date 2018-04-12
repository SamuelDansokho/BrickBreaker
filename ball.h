#ifndef BALL_H
#define BALL_H
#include "element.h"
#include <GL/glu.h>


class Ball : public Element
{
public:
    Ball();
    virtual ~Ball();
    void Display();
    void Update();
    virtual float getPosX();
    virtual float getPosY();
    int getSpeed();
    void setSpeed();

private:
   // float posX_;
   // float posY_;
    int speed_;



};

#endif // BALL_H
