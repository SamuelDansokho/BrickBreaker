#ifndef BRICK_H
#define BRICK_H
#include "element.h"
#include <GL/glu.h>
#include <QString>


class Brick : public Element
{
public:
    Brick(float posX,float posY);
    virtual ~Brick();
    void Display();
    void Update();
    virtual float getPosX();
    virtual float getPosY();
    void setState();
    QString getType();
private:

    float posX_;
    float posY_;
  //  bool state_;
   // QString type_;
};

#endif // BRICK_H
