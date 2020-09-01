#ifndef ECLAIRAGE_H
#define ECLAIRAGE_H

#include "ComposantsInstallationElect_global.h"

#include "Recepteur.h"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Eclairage : public Recepteur
{
public:
    Eclairage();
    Eclairage(float pAbsorbeeUnitaire, int quantite = 1, float cos = 1.0
              , QString designation = QString(), int numTableau = 0);

public:
    static int nbTotalEclairagesCrees;
    QString designationParDefaut();

private:
    void numeroter();
};

#endif // ECLAIRAGE_H
