#ifndef MESTYPES_H
#define MESTYPES_H

namespace TableauMesTypes
{
    enum TableauColumn
    {
        Designation = 0, Ks = 1, CosPhi = 2,
        Pinstallee = 3, Qinstallee = 4, Putilisee = 5,
        Qutilisee = 6, TableauEnAmont = 7, NumeroDuTableauEnAmont = 8,
        TypeDuTableau = 9, Numero = 10
    };
}

namespace RecepteurMesTypes
{
    enum RecepteurColumn
    {
        Designation = 0, Putile = 1, Quantite = 2, CosPhi = 3, Rendement = 4,
        Pasborbee = 5, Ks = 6, Ku = 7, Pinstallee = 8, Qinstallee = 9,
        Putilisee = 10, Qutilisee = 11, TableauEnAmont = 12, NumeroDuTableauEnAmont = 13,
        TypeDuRecepteur = 14, Numero = 15
    };
}

#endif // MESTYPES_H
