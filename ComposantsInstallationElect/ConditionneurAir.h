#ifndef CONDITIONNEURAIR_H
#define CONDITIONNEURAIR_H

#include "ComposantsInstallationElect_global.h"

#include "Recepteur.h"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT ConditionneurAir : public Recepteur
{
public:
    ConditionneurAir();
    ConditionneurAir(float pAbsorbeeUnitaire, int quantite = 1, float cos = 1.0
              , QString designation = QString(), int numTableau = 0);

public:
    static int nbTotalConditionneursAirCrees;
    QString designationParDefaut();

private:
    void numeroter();
};

#endif // CONDITIONNEURAIR_H
