#include "Cable.h"

Cable::Cable(QGraphicsScene * scene)
{
    m_scene = scene;
}

Cable::~Cable()
{

}

void Cable::connecter(Composant *pere, Composant *fils)
{
    fils->centrerV(pere);
    float x1, y1, x2, y2;
    x1 = pere->milieuBas().x();
    y1 = pere->milieuBas().y();

    x2 = fils->milieuHaut().x();
    y2 = fils->milieuHaut().y();

    setCableBrise(x1, y1, x2, y2, 0);
}

void Cable::connecter(Composant *pere, GroupeDeComposants fils, float espacement)
{
    if(fils.count() == 0)
        return;

    if(fils.count() == 1)
    {
        connecter(pere, (*fils.iteratorAt(0)));
        return;
    }

    int nb = fils.count();
    bool pair = (nb % 2 == 0);

    fils.centrerH(pere, espacement);

    float espace = 0.6 * pere->longueur()/(nb - 1);
    float xdepart = pere->x() + 0.2 * pere->longueur();
    float espaceh = hmaxBrisee() * pere->scale()/(nb/2);

    float xi = xdepart + (nb/2 - 1) * espace;
    float xj;

    if(pair)
    {
        xj = xi + espace;
    }else
    {
        xj = xi + 2 * espace;
    }

    int k = 0;
    for(int i = 0; i < nb; i++)
    {
        Cable * cable = new Cable(m_scene);
        m_scene->addItem(cable);
        float x2 = (*fils.iteratorAt(i))->milieuHaut().x();
        float y2 = (*fils.iteratorAt(i))->milieuHaut().y();

        float x1 = xdepart + i*espace;
        float y1 = pere->milieuBas().y();

        if((x2 >= xi) && (x2 <= xj))
        {
            setCableBrise(x2, y1, x2, y2);
            k++; // pour assurer la continuité
        }else
        {
            int median = nb/2 + 1;
            if(pair && (i+1 >= median))
            {
                median = nb/2;
            }

            if(i+1 <= median)
            {
                k++;
            }else
            {
                if(pair && (i+1 == median + 1)) // car 1221 pas 12321
                    k++;
                k--;
            }

            float h = espaceh * k;

            cable->setCableBrise(x1, y1, x2, y2, h);
        }
    }
}

void Cable::connecter(Composant *pere, GroupeDeComposants fils, QList<float> espacements)
{
    if(fils.count() == 0 || espacements.count() != fils.count() - 1)
        return;

    if(fils.count() == 1)
    {
        connecter(pere, (*fils.iteratorAt(0)));
        return;
    }

    int nb = fils.count();
    bool pair = (nb % 2 == 0);

    fils.centrerH(pere, espacements);

    float espace = 0.6 * pere->longueur()/(nb - 1);
    float xdepart = pere->x() + 0.2 * pere->longueur();
    float espaceh = hmaxBrisee() * pere->scale()/(nb/2);

    float xi = xdepart + (nb/2 - 1) * espace;
    float xj;

    if(pair)
    {
        xj = xi + espace;
    }else
    {
        xj = xi + 2 * espace;
    }

    int k = 0;
    for(int i = 0; i < nb; i++)
    {
        Cable * cable = new Cable(m_scene);
        m_scene->addItem(cable);
        float x2 = (*fils.iteratorAt(i))->milieuHaut().x();
        float y2 = (*fils.iteratorAt(i))->milieuHaut().y();

        float x1 = xdepart + i*espace;
        float y1 = pere->milieuBas().y();

        if((x2 >= xi) && (x2 <= xj))
        {
            setCableBrise(x2, y1, x2, y2);
            k++; // pour assurer la continuité
        }else
        {
            int median = nb/2 + 1;
            if(pair && (i+1 >= median))
            {
                median = nb/2;
            }

            if(i+1 <= median)
            {
                k++;
            }else
            {
                if(pair && (i+1 == median + 1)) // car 1221 pas 12321
                    k++;
                k--;
            }

            float h = espaceh * k;

            cable->setCableBrise(x1, y1, x2, y2, h);
        }
    }
}

void Cable::setCableBrise(float x1, float y1, float x2, float y2, float h1)
{
    float h;

    h = h1;

    QGraphicsLineItem * lineV1 = new QGraphicsLineItem();

    m_scene->addItem(lineV1);

    if(h != 0)
    {
        QGraphicsLineItem * lineH = new QGraphicsLineItem();
        QGraphicsLineItem * lineV2 = new QGraphicsLineItem();

        m_scene->addItem(lineH);
        m_scene->addItem(lineV2);

        lineV1->setLine(x1, y1, x1, y1 + h);
        lineH->setLine(x1, y1 + h, x2, y1 + h);
        lineV2->setLine(x2, y1 + h, x2, y2);
    }else
    {
        lineV1->setLine(x1, y1, x2, y2); // un trait droit
    }
}

void Cable::setCableBrise(QPoint p1, QPoint p2, float h1)
{
    setCableBrise(p1.x(), p1.y(), p2.x(), p2.y(),h1);
}
