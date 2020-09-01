#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPoint>
#include "GroupeDeComposants.h"
#include "Cable.h"

class GroupeDeComposants;

class Composant : public QGraphicsPixmapItem
{
public:
    enum TypeDeComposant
    {
        AutreComposant = 0, Transfo = 1, t_TGBT = 2, t_TS = 3, t_TD = 4,
        t_TER = 5, t_Eclairage = 6, t_PC = 7, t_Moteur = 8, t_Chauffage = 9,
        t_ConditionneurAir = 10, Local = 11, Extension = 12, Disjoncteur = 13
    };

public:
    Composant(QGraphicsItem * parent = 0, QGraphicsScene * scene = 0, QGraphicsScene * sceneMere = 0);
    Composant(const QPixmap & pixmap, QGraphicsItem * parent = 0, QGraphicsScene * scene = 0, QGraphicsScene * sceneMere = 0);
    Composant(TypeDeComposant type, QGraphicsItem * parent = 0, QGraphicsScene * scene = 0, QGraphicsScene * sceneMere = 0);

    ~Composant();

    float longueur()const;
    float hauteur()const;

    void setText(const QString & text);
    inline QString text()const{return QString();};
    void setTypeDeComposant(TypeDeComposant type);
    inline TypeDeComposant typeDeComposant()const{return m_typeDeCpt;};

    void centrer(const QGraphicsScene * reference);
    void centrerH(const QGraphicsScene * reference);
    void centrerV(const QGraphicsScene * reference);

    void centrerH(const Composant * cpt);
    void centrerV(const Composant * cpt);

    QPoint milieuBas()const;
    QPoint milieuHaut()const;

    void connecterA(Composant * fils);
    void connecterA(GroupeDeComposants fils, float espacement, bool appliquerNiveau = false, float niveau = 0.0);

private:
    QGraphicsTextItem * m_textItem;
    QGraphicsScene * m_scene;
    QGraphicsScene * m_sceneMere;
    TypeDeComposant m_typeDeCpt;

    void centrerText();

public:
    static QPixmap typeDeCptToPixmap(TypeDeComposant type);
};

#endif // COMPOSANT_H
