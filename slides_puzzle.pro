QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend.cpp \
    frontend.cpp \
    game.cpp \
    gameoptions.cpp \
    gamestate.cpp \
    iabletonotify.cpp \
    main.cpp \
    mainwindow.cpp \
    newgamewindow.cpp \
    notificationbox.cpp \
    tile.cpp \
    tilestable.cpp

HEADERS += \
    backend.h \
    frontend.h \
    game.h \
    gameoptions.h \
    gamestate.h \
    iabletonotify.h \
    mainwindow.h \
    newgamewindow.h \
    notificationbox.h \
    tile.h \
    tilestable.h

FORMS += \
    mainwindow.ui \
    newgamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
