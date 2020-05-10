QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brunering_send.cpp \
    elektrolytisk_fornikling_send.cpp \
    eloksering_send.cpp \
    elzink_send.cpp \
    fosfatering_send.cpp \
    galvanisering_send.cpp \
    glass_blaasing_send.cpp \
    hardforkromming_send.cpp \
    herding_send.cpp \
    kromatering_send.cpp \
    main.cpp \
    mainwindow.cpp \
    mottar.cpp \
    nitrering_send.cpp \
    offshore_lakkering_send.cpp \
    plasma_nitrering_send.cpp \
    pulverlakkering_send.cpp \
    sandblaasing_send.cpp \
    sender.cpp \
    sett_herding_send.cpp \
    sliping_send.cpp \
    syrevask_send.cpp \
    traadskjaering_send.cpp \
    vaatlakkering_send.cpp

HEADERS += \
    brunering_send.h \
    elektrolytisk_fornikling_send.h \
    eloksering_send.h \
    elzink_send.h \
    fosfatering_send.h \
    galvanisering_send.h \
    glass_blaasing_send.h \
    hardforkromming_send.h \
    herding_send.h \
    kromatering_send.h \
    mainwindow.h \
    mottar.h \
    nitrering_send.h \
    offshore_lakkering_send.h \
    plasma_nitrering_send.h \
    pulverlakkering_send.h \
    sandblaasing_send.h \
    sender.h \
    sett_herding_send.h \
    sliping_send.h \
    syrevask_send.h \
    traadskjaering_send.h \
    vaatlakkering_send.h

FORMS += \
    brunering_send.ui \
    elektrolytisk_fornikling_send.ui \
    eloksering_send.ui \
    elzink_send.ui \
    fosfatering_send.ui \
    galvanisering_send.ui \
    glass_blaasing_send.ui \
    hardforkromming_send.ui \
    herding_send.ui \
    kromatering_send.ui \
    mainwindow.ui \
    mottar.ui \
    nitrering_send.ui \
    offshore_lakkering_send.ui \
    plasma_nitrering_send.ui \
    pulverlakkering_send.ui \
    sandblaasing_send.ui \
    sender.ui \
    sett_herding_send.ui \
    sliping_send.ui \
    syrevask_send.ui \
    traadskjaering_send.ui \
    vaatlakkering_send.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
