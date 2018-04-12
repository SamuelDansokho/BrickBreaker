#ifndef PLANET_H
#define PLANET_H

#include <GL/glu.h>
#include <QColor>


// Classe dediee pour la gestion d'une planete
class Planet
{
public:
    // Constructeur avec parametres
    Planet(...);

    // Destructeur
    virtual ~Planet();

    // Methode d'affichage
    void Display(const float timeInDays) const;

private:
    // Paramètres
    // ...
};


#endif // PLANET_H
