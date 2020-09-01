#ifndef COMPOSANT_H
#define COMPOSANT_H

#include "ComposantsInstallationElect_global.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPoint>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QBitmap>
#include "InstallationGraphicDriver.h"
#include "Constantes.h"

#define AUTRE_NOMBRE "Autre nombre"

class InstallationGraphicDriver;

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Composant : public QGraphicsPixmapItem
{
public:    
    Composant(InstallationGraphicDriver * parent = 0);
    Composant(const QPixmap & pixmap, InstallationGraphicDriver * parent = 0);
    Composant(cstes::TypeDeComposant type, InstallationGraphicDriver * parent = 0);

    ~Composant();

    float longueur()const;
    float hauteur()const;

    float longueurRelle()const;
    float hauteurRelle()const;

    void setText(const QString & text);
    void setCaracteristiques(const QString & text);
    inline QString text()const{return QString();};
    void setTypeDeComposant(cstes::TypeDeComposant type);
    void setDesignation(const QString & designation);
    inline QString designation()const{return m_designation;};
    inline cstes::TypeDeComposant typeDeComposant()const{return m_typeDeCpt;};
    QString typeDeComposantStr()const;

    void centrer(const QGraphicsScene * reference);
    void centrerH(const QGraphicsScene * reference);
    void centrerV(const QGraphicsScene * reference);

    void centrerH(const Composant * cpt);
    void centrerV(const Composant * cpt);

    QPoint milieuBas()const;
    QPoint milieuHaut()const;

    void setMilieuHaut(float x, float y);

    void centrerText();
    void textBasVertical();
    void textCoteDroit();
    void setTextePostion(cstes::PositionDeTexte position);

    bool estUnTableau();
    bool estUnRecepteur();
    bool estUnLocal();
    bool estUnTranfo();

    inline cstes::TypeDeComposant getTypeDeComposant()const{return m_typeDeCpt;};

private:
    QGraphicsTextItem * m_textItem;
    QGraphicsTextItem * m_caracteristiquesItem;
    QGraphicsScene * m_scene;
    QGraphicsScene * m_sceneMere;
    InstallationGraphicDriver * m_parent;
    cstes::TypeDeComposant m_typeDeCpt;
    QString m_designation;

    Tableau::TypeDeTableau typeDeTableau(cstes::TypeDeComposant typeDeComposant);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    static QPixmap typeDeCptToPixmap(cstes::TypeDeComposant type);
    static QStringList listeDeTypeComposant();
    static cstes::TypeDeComposant stringToType(QString type);
    static QString typeToString(cstes::TypeDeComposant type);
    static bool estUnTableau(QString typeCpt);
    static bool estUnRecepteur(QString typeCpt);
    static bool estUnLocal(QString typeCpt);
};

#endif // COMPOSANT_H
