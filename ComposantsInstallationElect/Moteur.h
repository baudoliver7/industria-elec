#ifndef MOTEUR_H
#define MOTEUR_H

#include "ComposantsInstallationElect_global.h"

#include "Recepteur.h"

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Moteur : public Recepteur
{
public:
    Moteur();
    Moteur(float pUtileUnitaire, float rendement, int quantite = 1
              , float cos = 0.86, float ku = 0.75 , QString designation = QString()
              , int numTableau = 0);
    Moteur(float pAbsorbeeUnitaire, int quantite = 1, float cos = 0.86, float ku = 0.75
              , QString designation = QString(), int numTableau = 0);

public:
    static int nbTotalMoteursCrees;
    QString designationParDefaut();

private:
    void numeroter();
};

#endif // MOTEUR_H
