#include "GroupeDeComposants.h"

GroupeDeComposants::GroupeDeComposants(float y, float espacement)
{
    m_composants.clear();
    m_espacement = espacement;
    setY(y);
}

GroupeDeComposants::GroupeDeComposants(const GroupeDeComposants &gp)
{
    m_composants.clear();
    m_composants << gp.m_composants;
    m_espacement = gp.m_espacement;
    m_y = gp.m_y;
}

bool GroupeDeComposants::ajouterUnComposant(Composant *cpt, bool appliquerNiveau)
{
    if(!m_composants.contains(cpt))
    {
        if(!m_composants.isEmpty())
        {
            cpt->setX(m_composants.last()->x() + 0.1);
        }else
        {
            cpt->setX(0);
        }

        if(appliquerNiveau)
        {
            cpt->setY(m_y);
        }

        m_composants << cpt;
        return true;
    }

    return false;
}

void GroupeDeComposants::ajouterUnGroupe(GroupeDeComposants group, bool appliquerNiveau)
{
    for(int i = 0; i < group.composants().count(); i++)
    {
        ajouterUnComposant((*group.iteratorAt(i)), appliquerNiveau);
    }
}

void GroupeDeComposants::ajouterUnEltFictif(int position)
{
    int index = position - 1;
    if(index <0 || index >= m_composants.count())
        return;

    //rangerHComposants();

    Composant * elt = new Composant(m_composants.at(index)->pixmap());
    elt->setScale(m_composants.at(index)->scale());
    float x ;

    if(index == 0)
    {
        x = m_composants.at(0)->x()/2.0;
    }else
    {
        if(index == m_composants.count() - 1)
        {
            x = m_composants.at(index)->x() + 2.0;
        }else
        {
            x = m_composants.at(index - 1)->x()
                + (m_composants.at(index)->x() - m_composants.at(index - 1)->x())/2.0;
        }
    }

    elt->setX(x);

    m_composants.insert(index, elt);
}

void GroupeDeComposants::centrerH(const Composant *reference, float espacement)
{
    if(m_composants.isEmpty())
        return;

    int nb = m_composants.count();

    if(nb == 1)
    {
        (*iteratorAt(0))->centrerV(reference);
        return;
    }

    m_espacement = espacement;

    //rangerHComposants();

    if(nb % 2 == 1)  // si nb impair
    {
        int imedian = nb/2;
        (*iteratorAt(imedian))->centrerV(reference);

        for(int i = imedian - 1; i >= 0; i--)
        {
            float x = (*iteratorAt(i+1))->x() - (*iteratorAt(i))->longueur() - m_espacement;
            (*iteratorAt(i))->setX(x);
        }

        for(int i = imedian + 1; i < nb; i++)
        {
            float x = (*iteratorAt(i-1))->x() + (*iteratorAt(i-1))->longueur() + m_espacement;
            (*iteratorAt(i))->setX(x);
        }
    }else
    {
        // nb est pair
        int imedian1 = nb/2 - 1;
        int imedian2 = imedian1 + 1;

        float XMilieuRef = reference->x() + reference->longueur()/2.0;
        float x1 = XMilieuRef - (m_espacement/2.0 + (*iteratorAt(imedian1))->longueur());

        float x2 = XMilieuRef + m_espacement/2.0;

        (*iteratorAt(imedian1))->setX(x1);
        (*iteratorAt(imedian2))->setX(x2);

        for(int i = imedian1 - 1; i >= 0; i--)
        {
            float x = (*iteratorAt(i+1))->x() - (*iteratorAt(i))->longueur() - m_espacement;
            (*iteratorAt(i))->setX(x);
        }

        for(int i = imedian2 + 1; i < nb; i++)
        {
            float x = (*iteratorAt(i-1))->x() + (*iteratorAt(i-1))->longueur() + m_espacement;
            (*iteratorAt(i))->setX(x);
        }
    }
}

void GroupeDeComposants::centrerH(const Composant *reference, QList<float> espacements)
{
    if(m_composants.isEmpty() || espacements.count() != m_composants.count() - 1)
        return;

    int nb = m_composants.count();
    if(nb == 1)
    {
        (*iteratorAt(0))->centrerV(reference);
        return;
    }

    for(int i = 1; i < nb; i++)
    {
        float x = (*iteratorAt(i - 1))->x() + (*iteratorAt(i - 1))->longueur() + espacements.at(i - 1);

        (*iteratorAt(i))->setX(x);
    }

    centrerAutourDeX(reference->milieuBas().x());
}

QList<Composant*>::iterator GroupeDeComposants::iteratorOf(Composant *cpt)
{
    if(!m_composants.contains(cpt))
        return m_composants.end();

    int index = m_composants.indexOf(cpt);

    return iteratorAt(index);
}

QList<Composant*>::iterator GroupeDeComposants::iteratorAt(int index)
{
    if(index < 0 || index >= m_composants.count())
        return m_composants.end();

    QList<Composant*>::iterator it = m_composants.begin();

    for(int i = 1; i <= index; i++)
    {
        it++;
    }

    return it;
}

void GroupeDeComposants::rangerHComposants()
{
    for(int i = 0; i < m_composants.count() - 1; i++)
    {
        for(int j = i + 1; j < m_composants.count(); j++)
        {
            if(m_composants.at(i)->x() > m_composants.at(j)->x())
            {
                m_composants.swap(i,j);
            }
        }
    }
}

void GroupeDeComposants::rangerVComposants()
{
    for(int i = 0; i < m_composants.count() - 1; i++)
    {
        for(int j = i + 1; j < m_composants.count(); j++)
        {
            if(m_composants.at(i)->y() > m_composants.at(j)->y())
            {
                m_composants.swap(i,j);
            }
        }
    }
}

void GroupeDeComposants::centrerAutourDeX(float x)
{
    if(m_composants.isEmpty())
        return;

    float x_gc = m_composants.at(0)->x() + longueur()/2.0;
    float dx = x - x_gc;

    for(int i = 0; i < m_composants.count(); i++)
    {
        float l_x = (*iteratorAt(i))->x();
        (*iteratorAt(i))->setX(l_x + dx);
    }
}

float GroupeDeComposants::longueur()const
{
    if(m_composants.isEmpty())
        return 0.0;

    if(m_composants.count() == 1)
        return m_composants.at(0)->longueur();

    int nb = m_composants.count();
    return (m_composants.at(nb - 1)->x() - m_composants.at(0)->x() + m_composants.at(nb - 1)->longueur());
}

void GroupeDeComposants::setY(float y)
{
    m_y = y;

    for(int i = 0; i < m_composants.count(); i++)
    {
        (*iteratorAt(i))->setY(m_y);
    }
}
