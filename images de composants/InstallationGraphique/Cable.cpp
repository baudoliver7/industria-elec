#include "Cable.h"

Cable::Cable(QGraphicsScene * scene)
{
    m_scene = scene;
    m_scale = 1.0;
}

Cable::~Cable()
{

}

void Cable::connecter(Composant *pere, Composant *fils)
{
    m_scale = pere->scale();

    fils->centrerV(pere);
    float x1, y1, x2, y2;
    x1 = pere->x() + pere->longueur()/2.0;
    y1 = pere->y() + pere->hauteur();

    x2 = fils->x() + fils->longueur()/2.0;
    y2 = fils->y();

    setLine(x1, y1, x2, y2);
}

void Cable::connecter(Composant *pere, GroupeDeComposants fils, float espacement, bool appliquerNiveau, float niveau)
{
    m_scale = pere->scale();

    if(fils.count() == 0)
        return;

    if(fils.count() == 1)
    {
        connecter(pere, (*fils.iteratorAt(0)));
        return;
    }

    int nb = fils.count();

    fils.centrerH(pere, espacement, appliquerNiveau, niveau);

    float espace = 0.6*pere->longueur()/(nb - 1);
    float xdepart = pere->x() + 0.2 * pere->longueur();
    float espaceh = hmaxBrisee() * m_scale/(nb/2);

    for(int i = 0; i < nb; i++)
    {
        Cable * cable = new Cable(m_scene);
        m_scene->addItem(cable);
        float x1 = (*fils.iteratorAt(i))->milieuHaut().x();
        float y1 = (*fils.iteratorAt(i))->milieuHaut().y();

        float x2 = xdepart + i*espace;
        float y2 = pere->milieuBas().y();

        int median = nb/2 + 1;
        if((nb % 2 == 0) && (i+1 >= median))
        {
            median = nb/2;
        }

        float h = espaceh * abs(median - (i+1));

        cable->setCableBrise(x1, y1, x2, y2, h);
    }
}

void Cable::setCableBrise(float x1, float y1, float x2, float y2, float h1)
{
    float h;
    if(h1 <= 0.0 || h1 > hmaxBrisee())
    {
        h = hmaxBrisee() * m_scale;
    }else
    {
        h = h1 * m_scale;
    }

    QGraphicsLineItem * lineH = new QGraphicsLineItem();
    QGraphicsLineItem * lineV = new QGraphicsLineItem();

    m_scene->addItem(lineH);
    m_scene->addItem(lineV);

    setLine(x1, y1, x1, y1 - h);
    lineH->setLine(x1, y1 - h, x2, y1 - h);
    lineV->setLine(x2, y1 - h, x2, y2);
}

void Cable::setCableBrise(QPoint p1, QPoint p2, float h1)
{
    setCableBrise(p1.x(), p1.y(), p2.x(), p2.y(),h1);
}
