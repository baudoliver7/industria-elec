#include "Composant.h"

Composant::Composant(QGraphicsItem *parent, QGraphicsScene *scene, QGraphicsScene *sceneMere)
    : QGraphicsPixmapItem(parent, scene)
{
    m_scene = scene;
    m_sceneMere = sceneMere;
    m_typeDeCpt = AutreComposant;

    if(scene)
    {
        m_textItem = new QGraphicsTextItem(this, m_scene);
        m_textItem->setFont(QFont("Times", 16, QFont::Bold));
    }
}

Composant::Composant(const QPixmap &pixmap, QGraphicsItem *parent, QGraphicsScene *scene, QGraphicsScene *sceneMere)
    : QGraphicsPixmapItem(pixmap, parent, scene)
{
    m_scene = scene;
    m_sceneMere = sceneMere;
    m_typeDeCpt = AutreComposant;

    if(scene)
    {
        m_textItem = new QGraphicsTextItem(this, m_scene);
        m_textItem->setFont(QFont("Times", 16, QFont::Bold));
    }
}

Composant::Composant(TypeDeComposant type, QGraphicsItem *parent, QGraphicsScene *scene, QGraphicsScene *sceneMere)
    : QGraphicsPixmapItem(parent, scene)
{
    setTypeDeComposant(type);
    m_scene = scene;
    m_sceneMere = sceneMere;

    if(scene)
    {
        m_textItem = new QGraphicsTextItem(this, m_scene);
        m_textItem->setFont(QFont("Times", 16, QFont::Bold));
    }
}

float Composant::longueur()const
{
    return sceneBoundingRect().width();
}

float Composant::hauteur()const
{
    return sceneBoundingRect().height();
}

void Composant::setText(const QString &text)
{
    if(m_scene)
    {
        m_textItem->setPlainText(text);
        centrerText();
    }
}

void Composant::setTypeDeComposant(TypeDeComposant type)
{
    m_typeDeCpt = type;

    setPixmap(typeDeCptToPixmap(m_typeDeCpt));
}

void Composant::centrerText()
{
    float x = longueur()/2.0 - m_textItem->sceneBoundingRect().width()/2.0;
    float y = hauteur()/2.0 - m_textItem->sceneBoundingRect().height()/2.0;

    m_textItem->setPos(x,y);
}

void Composant::centrer(const QGraphicsScene *reference)
{
    float x = (reference->width() - longueur())/2.0;
    float y = (reference->height() - hauteur())/2.0;

    setPos(x, y);
}

void Composant::centrerH(const QGraphicsScene *reference)
{
    float x = (reference->width() - longueur())/2.0;

    setX(x);
}

void Composant::centrerH(const Composant * cpt)
{
    float y = cpt->y() + (cpt->hauteur() - hauteur())/2.0;

    setY(y);
}

void Composant::centrerV(const QGraphicsScene *reference)
{
    float y = (reference->height() - hauteur())/2.0;

    setY(y);
}

QPoint Composant::milieuBas()const
{
    float x = this->x() + longueur()/2.0;
    float y = this->y() + hauteur();

    return QPoint(x, y);
}

QPoint Composant::milieuHaut()const
{
    float x = this->x() + longueur()/2.0;
    float y = this->y();

    return QPoint(x, y);
}

void Composant::centrerV(const Composant *cpt)
{
    float x = cpt->x() + (cpt->longueur() - longueur())/2.0;

    setX(x);
}

void Composant::connecterA(Composant *fils)
{
    if(!m_sceneMere)
        return;

    Cable * cable = new Cable(m_sceneMere);
    m_sceneMere->addItem(cable);
    cable->connecter(this, fils);
}

void Composant::connecterA(GroupeDeComposants fils, float espacement, bool appliquerNiveau, float niveau)
{
    if(!m_sceneMere||fils.composants().isEmpty())
        return;

    Cable * cable = new Cable(m_sceneMere);
    m_sceneMere->addItem(cable);
    cable->connecter(this, fils, espacement, appliquerNiveau, niveau);
}

Composant::~Composant()
{
    if(m_textItem)
    {
        delete m_textItem;
    }
}

QPixmap Composant::typeDeCptToPixmap(TypeDeComposant type)
{
    QPixmap pixmap;

    switch(type)
    {
    case Transfo:
        pixmap.load(":images/transfo.png");
        break;
    case t_TGBT:
        pixmap.load(":images/TGBT.png");
        break;
    case t_TS:
        pixmap.load(":images/TS.png");
        break;
    case t_TD:
        pixmap.load(":images/TD.png");
        break;
    case t_TER:
        pixmap.load(":images/TER.png");
        break;
    case t_Eclairage:
        pixmap.load(":images/eclairage.png");
        break;
    case t_PC:
        pixmap.load(":images/prise de courant.png");
        break;
    case t_Moteur:
        pixmap.load(":images/moteur.png");
        break;
    case t_Chauffage:
        pixmap.load(":images/Chauffage.png");
        break;
    case t_ConditionneurAir:
        pixmap.load(":images/climatiseur.png");
        break;
    case Local:
        pixmap.load(":images/Local.png");
        break;
    case Extension:
        pixmap.load(":images/Extension.png");
        break;
    case Disjoncteur:
        pixmap.load(":images/disjoncteur.png");
        break;
    default:
        pixmap.load(":images/autre récepteur.png");
    }

    return pixmap;
}

