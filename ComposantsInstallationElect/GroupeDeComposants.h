#ifndef GROUPEDECOMPOSANTS_H
#define GROUPEDECOMPOSANTS_H

#include "Composant.h"
#include <QList>

class Composant;

class GroupeDeComposants
{
public:
    GroupeDeComposants(float y = 0.0, float espacement = 0.0);
    GroupeDeComposants(const GroupeDeComposants & gp);

    bool ajouterUnComposant(Composant * cpt, bool appliquerNiveau = true);    
    void ajouterUnGroupe(GroupeDeComposants group, bool appliquerNiveau = true);
    void ajouterUnEltFictif(int position);
    void centrerH(const Composant * reference, float espacement);
    void centrerH(const Composant * reference, QList<float> espacements);
    inline int count()const{return m_composants.count();};
    QList<Composant*>::iterator iteratorOf(Composant * cpt);
    QList<Composant*>::iterator iteratorAt(int index);
    float longueur()const;
    inline float espacement()const{return m_espacement;};
    inline QList<Composant*> composants()const{return m_composants;};
    inline void setEspacement(float espacement){m_espacement = espacement;};
    void setY(float y);

private:
    QList<Composant*> m_composants;
    float m_espacement;
    float m_y;

    void rangerHComposants();
    void rangerVComposants();
    void centrerAutourDeX(float x);
};

#endif // GROUPEDECOMPOSANTS_H
