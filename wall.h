#ifndef WALL_H
#define WALL_H
#include "element.h"
#include <GL/glu.h>
#include <QString>

class Wall : public Element
{
public:
    Wall();
    virtual ~Wall();
    virtual float getPosX();
    virtual float getPosY();
    void Display();
    void Update();

private:
    QString type_;
};

#endif // WALL_H
