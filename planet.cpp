#include "planet.h"


Planet::Planet(...)
{
    // Initialisation des paramètres
    // ...

    // Creation de la quadrique
    // ...
}


Planet::~Planet()
{
    // Destruction de la quadrique
    // ...
}


void Planet::Display(const float timeInDays) const
{
    glPushMatrix();

    // Transformations pour la periode de revolution
    // ...

    // Transformation pour la periode de rotation
    // ...

    // Couleur de l'objet
    // ...

    // Affichage de la quadrique
    // ...

    glPopMatrix();
}
