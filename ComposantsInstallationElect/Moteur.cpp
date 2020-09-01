#include "Moteur.h"

int Moteur::nbTotalMoteursCrees = 0;

Moteur::Moteur():Recepteur()
{
    //numeroter();
    m_typeDeRecepteur = Recepteur::ForceMotrice;
    m_designation = QObject::tr("moteur %1").arg(m_numero);
    m_ku = 0.75;
}

Moteur::Moteur(float pUtileUnitaire, float rendement, int quantite, float cos, float ku, QString designation, int numTableau):
Recepteur(pUtileUnitaire, rendement, quantite, cos, ku, designation, Recepteur::ForceMotrice, numTableau)
{
    //numeroter();
    m_typeDeRecepteur = Recepteur::ForceMotrice;
}

Moteur::Moteur(float pAbsorbeeUnitaire, int quantite, float cos, float ku, QString designation, int numTableau):
        Recepteur(pAbsorbeeUnitaire, quantite, cos, ku, designation, Recepteur::ForceMotrice, numTableau)
{
    //numeroter();
    m_typeDeRecepteur = Recepteur::ForceMotrice;
}

QString Moteur::designationParDefaut()
{
    return QObject::tr("moteur %1").arg(m_numero);
}


void Moteur::numeroter()
{
    nbTotalMoteursCrees++;
    m_numero = nbTotalMoteursCrees;
}
