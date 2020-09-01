#ifndef TRANSFORMATEUR_H
#define TRANSFORMATEUR_H

#include "ComposantsInstallationElect_global.h"
#include <QStringList>

#define PUTILISATION_MAX 1412.55

class COMPOSANTSINSTALLATIONELECTSHARED_EXPORT Transformateur
{
    enum TransfoColumn
    {
        Ka = 0, Temperature = 1, PUtilisation = 2, Cos_Phi = 3
    };

public:
    Transformateur(float ka, float temperature, float pUtilisation = 0, float cos_phi = 0.86);
    Transformateur(const QStringList & infos);

    inline float ka()const{return m_ka;};
    inline float ki()const{return m_ki;};
    inline int temperature()const{return m_temperature;};
    inline float pUtilisation()const{return m_pUtilisation;};
    inline float cosPhi()const{return m_cosPhi;};
    float puissanceKVA()const;
    QStringList infosDuTransfo()const;

    void setKa(float ka);
    void setTemperature(int temp_degreeC);
    void setPUtilisation(float puissance);
    void setCosPhi(float cos);
private:
    float m_ka;
    float m_ki;
    int m_temperature;
    float m_pUtilisation;
    float m_cosPhi;

public:
    static float temperatureToKi(int temp);
    static bool infosTransfoValides(QStringList infos);
    static QStringList transfoToInfos(Transformateur t);
    static Transformateur infosToTransfo(QStringList infos);
};

#endif // TRANSFORMATEUR_H
