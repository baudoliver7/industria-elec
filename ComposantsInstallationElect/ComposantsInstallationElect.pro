# -------------------------------------------------
# Project created by QtCreator 2011-07-18T22:45:43
# -------------------------------------------------
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = ComposantsInstallationElect
TEMPLATE = lib
DEFINES += COMPOSANTSINSTALLATIONELECT_LIBRARY
SOURCES += ComposantsInstallationElect.cpp \
    Tableau.cpp \
    Recepteur.cpp \
    installation.cpp \
    Composant.cpp \
    Cable.cpp \
    GroupeDeComposants.cpp \
    InstallationGraphicDriver.cpp \
    Local.cpp \
    Transformateur.cpp
HEADERS += ComposantsInstallationElect.h \
    ComposantsInstallationElect_global.h \
    Tableau.h \
    Recepteur.h \
    installation.h \
    Composant.h \
    Cable.h \
    GroupeDeComposants.h \
    InstallationGraphicDriver.h \
    Local.h \
    Transformateur.h \
    Constantes.h
RESOURCES += images.qrc
FORMS += 
