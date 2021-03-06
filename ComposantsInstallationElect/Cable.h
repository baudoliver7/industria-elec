#ifndef CABLE_H
#define CABLE_H

#include <QGraphicsLineItem>
#include <QGraphicsScene>

#include "GroupeDeComposants.h"
#include "Composant.h"

class Composant;
class GroupeDeComposants;

class Cable : public QGraphicsLineItem
{
public:
    Cable(QGraphicsScene * scene);
    ~Cable();

    void connecter(Composant * pere, Composant * fils);
    void connecter(Composant * pere, GroupeDeComposants fils, float espacement);
    void connecter(Composant * pere, GroupeDeComposants fils, QList<float> espacements);
    void setCableBrise(float x1, float y1, float x2, float y2, float h1 = 0.0);
    void setCableBrise(QPoint p1, QPoint p2, float h1 = 0.0);
    inline float hmaxBrisee()const{return 30.0;};

private:
    QGraphicsScene * m_scene;
};

#endif // CABLE_H
