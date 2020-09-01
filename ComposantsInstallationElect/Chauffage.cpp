#include "Chauffage.h"

int Chauffage::nbTotalChauffagesCrees = 0;

Chauffage::Chauffage():Recepteur()
{
    //numeroter();

    m_ku = 1;
    m_rendement = 1;
    m_typeDeRecepteur = Recepteur::Chauffage;
}

Chauffage::Chauffage(float pAbsorbeeUnitaire, int quantite, float cos, QString designation, QString nomDuParent):
        Recepteur(pAbsorbeeUnitaire, quantite, cos, 1.0, designation, Recepteur::Chauffage, nomDuParent)
{
    m_pUtileUnitaire = pAbsorbeeUnitaire;
    m_typeDeRecepteur = Recepteur::Chauffage;
}
