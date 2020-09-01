#include "Transformateur.h"

Transformateur::Transformateur(float ka, float temperature, float pUtilisation, float cos_phi)
{
    setKa(ka);
    setTemperature(temperature);
    setPUtilisation(pUtilisation);
    setCosPhi(cos_phi);
}

Transformateur::Transformateur(const QStringList & infos)
{
    *this = infosToTransfo(infos);
}

float Transformateur::puissanceKVA()const
{
    float puissance = m_pUtilisation * m_ka / (m_cosPhi * m_ki);

    if(puissance <= 25)
        puissance = 25;
    else if (puissance <= 50)
        puissance = 50;
    else if (puissance <= 100)
        puissance = 100;
    else if (puissance <= 160)
        puissance = 160;
    else if (puissance <= 250)
        puissance = 250;
    else if (puissance <= 400)
        puissance = 400;
    else if (puissance <= 630)
        puissance = 630;
    else if (puissance <= 800)
        puissance = 800;
    else if (puissance <= 1000)
        puissance = 1000;
    else if (puissance <= 1250)
        puissance = 1250;
    else if (puissance <= 1600)
        puissance = 1600;
    else if (puissance <= 2000)
        puissance = 2000;
    else if (puissance <= 2500)
        puissance = 2500;
    else
        puissance = 3150; // sinon la dernière puissance

    return puissance;
}

QStringList Transformateur::infosDuTransfo()const
{
    return transfoToInfos(*this);
}

void Transformateur::setCosPhi(float cos)
{
    if(cos >= 0.86 && cos <= 1)
    {
        m_cosPhi = cos;
    }
}

void Transformateur::setKa(float ka)
{
    if(ka >= 1.2 && ka <= 1.4)
    {
        m_ka = ka;
    }
}

void Transformateur::setTemperature(int temp_degreeC)
{
    if((temp_degreeC >= 0 && temp_degreeC <= 50)
        && (temperatureToKi(temp_degreeC) != -1))
    {
        m_temperature = temp_degreeC;
        m_ki = temperatureToKi(m_temperature);
    }
}

void Transformateur::setPUtilisation(float puissance)
{
    if(puissance >= 0 && puissance <= PUTILISATION_MAX)
    {
        m_pUtilisation = puissance;
    }
}

float Transformateur::temperatureToKi(int temp)
{
    float ki;

    switch(temp)
    {
    case 0:
        ki = 1.16;
        break;
    case 10:
        ki = 1.08;
        break;
    case 20:
        ki = 1;
        break;
    case 30:
        ki = 0.91;
        break;
    case 40:
        ki = 0.82;
        break;
    case 50:
        ki = 0.73;
        break;
    default:
        ki = -1;
    }

    return ki;
}

bool Transformateur::infosTransfoValides(QStringList infos)
{
    return (infos.count() == transfoToInfos(Transformateur(1.2,40)).count());
}

Transformateur Transformateur::infosToTransfo(QStringList infos)
{
    Transformateur t(infos.at(Ka).toFloat()
                     , infos.at(Temperature).toFloat()
                     , infos.at(PUtilisation).toFloat()
                     , infos.at(Cos_Phi).toFloat());

    return t;
}

QStringList Transformateur::transfoToInfos(Transformateur t)
{
    QStringList l;

    l       << QString::number(t.ka())
            << QString::number(t.temperature())
            << QString::number(t.pUtilisation())
            << QString::number(t.cosPhi());

    return l;
}
