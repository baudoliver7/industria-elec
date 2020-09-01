#ifndef PRISEDECOURANT_H
#define PRISEDECOURANT_H

#include "ComposantsInstallationElect_global.h"

#include "Recepteur.h"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT PriseDeCourant : public Recepteur
{
public:
    PriseDeCourant();
    PriseDeCourant(float pAbsorbeeUnitaire, int quantite = 1, float ku = 0.5
                   , QString designation = QString(), int numTableau = 0);

public:
    static int nbTotalPCCrees;
    QString designationParDefaut();

private:
    void numeroter();
    float ksParDefaut();
};

#endif // PRISEDECOURANT_H
