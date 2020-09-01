#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H

#include "Recepteur.h"

class Chauffage : public Recepteur
{
public:
    Chauffage();
    Chauffage(float pAbsorbeeUnitaire, int quantite = 1, float cos = 1.0
              , QString designation = QString(), QString nomDuParent = QString());
};

#endif // CHAUFFAGE_H
