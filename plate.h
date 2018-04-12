#ifndef PLATE_H
#define PLATE_H
#include "element.h"
#include <GL/glu.h>
#include <QString>


class Plate : public Element
{
public:
    Plate(float posX,float posY,int size);
    virtual ~Plate();
    void Display();
    void Update();
    //QString getSize();
    float posX_;
    float posY_;
    int size_;
    virtual float getPosX();
    virtual float getPosY();
    virtual void setPosX(float posX);
    virtual void setPosY(float posY);


private:

   // QString size_;
};

#endif // PLATE_H
