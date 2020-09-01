#include "Eclairage.h"

int Eclairage::nbTotalEclairagesCrees = 0;

Eclairage::Eclairage():Recepteur()
{
    //numeroter();

    m_ku = 1;
    m_rendement = 1;
    m_typeDeRecepteur = Recepteur::Eclairage;
    m_designation = QObject::tr("lampe %1").arg(m_numero);
}

Eclairage::Eclairage(float pAbsorbeeUnitaire, int quantite, float cos, QString designation, int numTableau):
 Recepteur(pAbsorbeeUnitaire, quantite, cos, 1.0, designation, Recepteur::Eclairage, numTableau)
{
    //numeroter();
    m_pUtileUnitaire = m_pAbsorbeeUnitaire;
    m_typeDeRecepteur = Recepteur::Eclairage;
}

QString Eclairage::designationParDefaut()
{
    return QObject::tr("lampe %1").arg(m_numero);
}


void Eclairage::numeroter()
{
    nbTotalEclairagesCrees++;
    m_numero = nbTotalEclairagesCrees;
}
