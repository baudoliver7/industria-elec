#include "ConditionneurAir.h"

int ConditionneurAir::nbTotalConditionneursAirCrees = 0;

ConditionneurAir::ConditionneurAir():Recepteur()
{
    //numeroter();

    m_ku = 1;
    m_rendement = 1;
    m_typeDeRecepteur = Recepteur::ConditionnementAir;
    m_designation = QObject::tr("conditionneur %1").arg(m_numero);
}

ConditionneurAir::ConditionneurAir(float pAbsorbeeUnitaire, int quantite, float cos, QString designation, int numTableau):
        Recepteur(pAbsorbeeUnitaire, quantite, cos, 1.0, designation, Recepteur::ConditionnementAir, numTableau)
{
    //numeroter();
    m_pUtileUnitaire = pAbsorbeeUnitaire;
    m_typeDeRecepteur = Recepteur::ConditionnementAir;
}

void ConditionneurAir::numeroter()
{
    nbTotalConditionneursAirCrees++;
    m_numero = nbTotalConditionneursAirCrees;
}

QString ConditionneurAir::designationParDefaut()
{
    return QObject::tr("conditionneur d'air %1").arg(m_numero);
}
