#ifndef CONSTANTES_H
#define CONSTANTES_H

namespace cstes {
    enum TypeDeComposant
    {
        AucunComposant = -1, AutreComposant = 0, Transfo = 1, t_TGBT = 2, t_TS = 3, t_TD = 4,
        t_TER = 5, t_Eclairage = 6, t_PC = 7, t_Moteur = 8, t_Chauffage = 9,
        t_ConditionneurAir = 10, Local_ecl = 11, Local_fm = 12, t_Extension = 13, Disjoncteur = 14
    };

    enum PositionDeTexte
    {
        TextCache, TextCentre, TextCoteDroit, TextBasVertical
    };
}

#endif // CONSTANTES_H
