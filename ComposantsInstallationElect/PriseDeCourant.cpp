#include "PriseDeCourant.h"

int PriseDeCourant::nbTotalPCCrees = 0;

PriseDeCourant::PriseDeCourant():Recepteur()
{
    //numeroter();

    m_ku = 0.5;
    m_ks = ksParDefaut();
    m_rendement = 1;
    m_typeDeRecepteur = Recepteur::PriseDeCourant;
    nommerParDefaut("prise de courant");
}

PriseDeCourant::PriseDeCourant(float pAbsorbeeUnitaire, int quantite, float ku, QString designation, int numTableau):
    Recepteur(pAbsorbeeUnitaire, quantite, 1.0, ku, designation, Recepteur::Eclairage, numTableau)
{
    //numeroter();

    m_typeDeRecepteur = Recepteur::PriseDeCourant;
    m_pUtileUnitaire = pAbsorbeeUnitaire;
    m_ks = ksParDefaut();
}

QString PriseDeCourant::designationParDefaut()
{
    return QObject::tr("prise de courant %1").arg(m_numero);
}

void PriseDeCourant::numeroter()
{
    nbTotalPCCrees++;
    m_numero = nbTotalPCCrees;
}

float PriseDeCourant::ksParDefaut()
{
    return (0.1 + 0.9/m_quantite);
}
