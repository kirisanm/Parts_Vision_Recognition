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
    elektrolytisk_fornikling_send.cpp \
    eloksering_send.cpp \
    elzink_send.cpp \
    fosfatering_send.cpp \
    hardforkromming_send.cpp \
    kromatering_send.cpp \
    main.cpp \
    mainwindow.cpp \
    mottar.cpp \
    offshore_lakkering_send.cpp \
    pulverlakkering_send.cpp \
    sender.cpp \
    vaatlakkering_send.cpp

HEADERS += \
    elektrolytisk_fornikling_send.h \
    eloksering_send.h \
    elzink_send.h \
    fosfatering_send.h \
    hardforkromming_send.h \
    kromatering_send.h \
    mainwindow.h \
    mottar.h \
    offshore_lakkering_send.h \
    pulverlakkering_send.h \
    sender.h \
    vaatlakkering_send.h

FORMS += \
    elektrolytisk_fornikling_send.ui \
    eloksering_send.ui \
    elzink_send.ui \
    fosfatering_send.ui \
    hardforkromming_send.ui \
    kromatering_send.ui \
    mainwindow.ui \
    mottar.ui \
    offshore_lakkering_send.ui \
    pulverlakkering_send.ui \
    sender.ui \
    vaatlakkering_send.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
