#include "Composant.h"
#include <QApplication>

Composant::Composant(InstallationGraphicDriver * parent)
{       
    m_parent = parent;
    m_typeDeCpt = cstes::AutreComposant;

    setFlag(Composant::ItemIsSelectable);
    m_textItem = new QGraphicsTextItem(this);
    m_textItem->setFont(QFont("Times", 20, QFont::Bold));

    m_caracteristiquesItem = new QGraphicsTextItem(this);
    m_caracteristiquesItem->setFont(QFont("Times", 20));
}

Composant::Composant(const QPixmap &pixmap, InstallationGraphicDriver *parent)
{
    m_parent = parent;
    setPixmap(pixmap);
    m_typeDeCpt = cstes::AutreComposant;

    setFlag(Composant::ItemIsSelectable);
    m_textItem = new QGraphicsTextItem(this);
    m_textItem->setFont(QFont("Times", 20, QFont::Bold));

    m_caracteristiquesItem = new QGraphicsTextItem(this);
    m_caracteristiquesItem->setFont(QFont("Times", 20));
}

Composant::Composant(cstes::TypeDeComposant type, InstallationGraphicDriver *parent)    
{
    m_parent = parent;
    setTypeDeComposant(type);

    setFlag(Composant::ItemIsSelectable);
    m_textItem = new QGraphicsTextItem(this);
    m_textItem->setFont(QFont("Times", 20, QFont::Bold));

    m_caracteristiquesItem = new QGraphicsTextItem(this);
    m_caracteristiquesItem->setFont(QFont("Times", 20));
}

float Composant::longueur()const
{
    return sceneBoundingRect().width();
}

float Composant::hauteur()const
{
    return sceneBoundingRect().height();
}

float Composant::longueurRelle()const
{
    return boundingRect().width();
}

float Composant::hauteurRelle()const
{
    return boundingRect().height();
}

void Composant::setText(const QString &text)
{
    if(m_textItem)
    {
        m_textItem->setPlainText(text);
    }
}

void Composant::setCaracteristiques(const QString &text)
{
    if(m_caracteristiquesItem)
    {
        m_caracteristiquesItem->setPlainText(text);


        if(estUnTableau())
        {
            float x = this->x();
            float y = this->y() - m_caracteristiquesItem->boundingRect().height();

            m_caracteristiquesItem->setPos(x,y);
        }else
        {
            if(estUnRecepteur() || estUnLocal())
            {
                m_caracteristiquesItem->setRotation(90.0);
                float x = milieuBas().x() - 10.0 * scale();
                float y = this->milieuBas().y() + 10.0 * scale();

                m_caracteristiquesItem->setPos(x,y);
            }else
            {
                if(estUnTranfo())
                {
                    float x = this->x() + longueur() + 10.0 * scale();
                    float y = hauteur()/2.0 + 10.0 * scale();

                    m_caracteristiquesItem->setPos(x,y);
                }
            }
        }
    }
}

void Composant::setTypeDeComposant(cstes::TypeDeComposant type)
{
    m_typeDeCpt = type;

    setPixmap(typeDeCptToPixmap(m_typeDeCpt));
}

void Composant::setDesignation(const QString & designation)
{
    m_designation = designation;

    setText(designation);
}

QString Composant::typeDeComposantStr()const
{
    return typeToString(m_typeDeCpt);
}

void Composant::centrerText()
{
    m_textItem->setVisible(true);

    float x = longueur()/2.0 - m_textItem->boundingRect().width()/2.0;
    float y = hauteur()/2.0 - m_textItem->boundingRect().height()/2.0;

    m_textItem->setPos(x,y);
}

void Composant::textBasVertical()
{
    m_textItem->setVisible(true);

    m_textItem->setRotation(90.0);
    float x = milieuBas().x() + m_textItem->boundingRect().height()/2.0;
    float y = this->milieuBas().y() + 10.0 * scale();

    m_textItem->setPos(x,y);
}

void Composant::textCoteDroit()
{
    m_textItem->setVisible(true);

    float x = this->x() + longueur() + 10.0 * scale();
    float y = hauteur()/2.0 - m_textItem->boundingRect().height()/2.0;

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

void Composant::setMilieuHaut(float x, float y)
{
    float dx = longueur()/2.0;

    setPos(x - dx, y);
}

void Composant::centrerV(const Composant *cpt)
{
    float x = cpt->x() + (cpt->longueur() - longueur())/2.0;

    setX(x);
}

Composant::~Composant()
{
    if(m_textItem)
    {
        delete m_textItem;
    }
}

QPixmap Composant::typeDeCptToPixmap(cstes::TypeDeComposant type)
{
    QPixmap pixmap;

    switch(type)
    {
    case cstes::Transfo:
        pixmap.load(":images/transfo.png");
        break;
    case cstes::t_TGBT:
        pixmap.load(":images/TGBT.png");
        break;
    case cstes::t_TS:
        pixmap.load(":images/TS.png");
        break;
    case cstes::t_TD:
        pixmap.load(":images/TD.png");
        break;
    case cstes::t_TER:
        pixmap.load(":images/TER.png");
        break;
    case cstes::t_Eclairage:
        pixmap.load(":images/eclairage.png");
        break;
    case cstes::t_PC:
        pixmap.load(":images/prise de courant.png");
        break;
    case cstes::t_Moteur:
        pixmap.load(":images/moteur.png");
        break;
    case cstes::t_Chauffage:
        pixmap.load(":images/Chauffage.png");
        break;
    case cstes::t_ConditionneurAir:
        pixmap.load(":images/climatiseur.png");
        break;
    case cstes::Local_ecl:
        pixmap.load(":images/Local_ecl.png");
        break;
    case cstes::Local_fm:
        pixmap.load(":images/Local_fm.png");
        break;
    case cstes::t_Extension:
        pixmap.load(":images/Extension.png");
        break;
    case cstes::Disjoncteur:
        pixmap.load(":images/disjoncteur.png");
        break;
    default:
        pixmap.load(":images/autre récepteur.png");
    }

    return pixmap;
}

void Composant::mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
{
    if(estUnTranfo())
    {
        emit m_parent->lancerSignalEditerTransfo();
    }else
    {
        if(estUnTableau())
        {
            emit m_parent->lancerSignalEditerTableau(m_designation);
        }else
        {
            if(estUnLocal())
            {
                emit m_parent->lancerSignalEditerLocal(m_designation);
            }else
            {
                // c'est un récepteur
                emit m_parent->lancerSignalEditerRecepteur(m_designation);
            }
        }
    }
}

void Composant::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeDeCpt) {
    case cstes::t_TGBT:
        m_parent->lancerSignalClickSurTGBT();
        break;
    case cstes::t_TS:
        m_parent->lancerSignalClickSurTableauSec();
        break;
    case cstes::t_TD:
        m_parent->lancerSignalClickSurTableauDiv();
        break;
    case cstes::t_TER:
        m_parent->lancerSignalClickSurTableauTer();
        break;
    default:
        m_parent->lancerSignalClickSurRecepteur();
        break;
    }
}

void Composant::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if(!estUnTranfo()) // on n'affiche de menu contextuel pour le transfo
    {
        setSelected(true);
        m_parent->afficherMenuContextuel(this, event);
    }
}

Tableau::TypeDeTableau Composant::typeDeTableau(cstes::TypeDeComposant typeDeComposant)
{
    Tableau::TypeDeTableau type;

    switch(typeDeComposant)
    {
    case cstes::t_TGBT:
        type = Tableau::TGBT;
        break;
    case cstes::t_TS:
        type = Tableau::TableauSecondaire;
        break;
    case cstes::t_TD:
        type = Tableau::CoffretDivisionnaire;
        break;
    case cstes::t_TER:
        type = Tableau::Terminal;
        break;
    default:
        type = Tableau::AucunType;
    }

    return type;
}

void Composant::setTextePostion(cstes::PositionDeTexte position)
{
    switch(position)
    {
    case cstes::TextCache:
        m_textItem->setVisible(false);
        break;
    case cstes::TextBasVertical:
        textBasVertical();
        break;
    case cstes::TextCentre:
        centrerText();
        break;
    case cstes::TextCoteDroit:
        textCoteDroit();
        break;
    }
}

bool Composant::estUnLocal()
{
    return estUnLocal(typeDeComposantStr());
}

bool Composant::estUnRecepteur()
{
    return estUnRecepteur(typeDeComposantStr());
}

bool Composant::estUnTableau()
{
    return estUnTableau(typeDeComposantStr());
}

bool Composant::estUnTranfo()
{
    return (m_typeDeCpt == cstes::Transfo);
}

QStringList Composant::listeDeTypeComposant()
{
    QStringList list;
    list    << "Autre composant"
            << "Transformateur"
            << "TGBT"
            << "Tableau secondaire"
            << "Tableau divisionnaire"
            << "Terminal"
            << "Eclairage"
            << "Prise de courant"
            << "Moteur"
            << "Chauffage"
            << "Conditionneur d'air"
            << "Local éclairage"
            << "Local force motrice"
            << "Extension"
            << "Disjoncteur";

   return list;
}

cstes::TypeDeComposant Composant::stringToType(QString type)
{
    if(listeDeTypeComposant().contains(type))
    {
        return (cstes::TypeDeComposant)listeDeTypeComposant().indexOf(type);
    }else
    {
        return cstes::AucunComposant; // aucun composant
    }
}

QString Composant::typeToString(cstes::TypeDeComposant type)
{
    return listeDeTypeComposant().at(type);
}

bool Composant::estUnLocal(QString typeCpt)
{
    cstes::TypeDeComposant type = stringToType(typeCpt);
    if(type == cstes::Local_ecl || type == cstes::Local_fm)
    {
        return true;
    }

    return false;
}

bool Composant::estUnRecepteur(QString typeCpt)
{
    cstes::TypeDeComposant type = stringToType(typeCpt);
    if(type == cstes::t_Eclairage || type == cstes::t_Moteur || type == cstes::t_Chauffage || type == cstes::t_ConditionneurAir || type == cstes::t_PC || type == cstes::AutreComposant)
    {
        return true;
    }

    return false;
}

bool Composant::estUnTableau(QString typeCpt)
{
    cstes::TypeDeComposant type = stringToType(typeCpt);
    if(type == cstes::t_TD || type == cstes::t_TER || type == cstes::t_TS || type == cstes::t_TGBT)
    {
        return true;
    }

    return false;
}
