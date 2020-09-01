# -------------------------------------------------
# Project created by QtCreator 2011-07-17T18:16:19
# -------------------------------------------------
QT += xml \
    sql
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets \
    printsupport
TARGET = EvaluationDePuissance
TEMPLATE = app
SOURCES += main.cpp \
    EvPuissMethod1.cpp \
    BDFormulaireDeTableau.cpp \
    BDFormulaireDeRecepteur.cpp \
    DialogNbDeElement.cpp \
    mainwindow.cpp \
    BDProprietesDesCpts.cpp \
    BDFormulaireDeLocal.cpp \
    BDParamTransfo.cpp \
    BDChoixDeMoteur.cpp \
    EvPuissMethod2.cpp \
    BDApropos.cpp \
    FrmAccueil.cpp \
    m2datasource.cpp \
    filsdatasource.cpp \
    armoiredatasource.cpp
HEADERS += EvPuissMethod1.h \
    BDFormulaireDeTableau.h \
    BDFormulaireDeRecepteur.h \
    DialogNbDeElement.h \
    mainwindow.h \
    BDProprietesDesCpts.h \
    BDFormulaireDeLocal.h \
    BDParamTransfo.h \
    BDChoixDeMoteur.h \
    EvPuissMethod2.h \
    BDApropos.h \
    FrmAccueil.h \
    m2datasource.h \
    filsdatasource.h \
    armoiredatasource.h \
    MesConstantes.h
FORMS += BDFormulaireDeTableau.ui \
    BDFormulaireDeRecepteur.ui \
    EvPuissMethod1.ui \
    DialogNbDeElement.ui \
    mainwindow.ui \
    BDProprietesDesCpts.ui \
    BDFormulaireDeLocal.ui \
    BDParamTransfo.ui \
    BDChoixDeMoteur.ui \
    EvPuissMethod2.ui \
    BDApropos.ui \
    FrmAccueil.ui
INCLUDEPATH += $$quote(../ComposantsInstallationElect)
LIBS += $$quote(../ComposantsInstallationElect/debug/ComposantsInstallationElect.dll)
INCLUDEPATH += ncreport/include
LIBS += ncreport/lib/libNCReport2.a
RESOURCES += boutons.qrc \
    images.qrc
RC_FILE = myapp.rc
