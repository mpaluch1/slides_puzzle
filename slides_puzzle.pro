QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += cimg_display=0

QMAKE_CXXFLAGS += -Wno-null-pointer-arithmetic -Wno-char-subscripts -Wno-class-memaccess

SOURCES += \
    backend.cpp \
    config.cpp \
    congratswindow.cpp \
    frontend.cpp \
    game.cpp \
    gameoptions.cpp \
    gamestate.cpp \
    iabletonotify.cpp \
    main.cpp \
    mainwindow.cpp \
    newgamewindow.cpp \
    notificationbox.cpp \
    picture.cpp \
    result.cpp \
    resultstable.cpp \
    resultstablesaver.cpp \
    resultswindow.cpp \
    tile.cpp \
    tilestable.cpp

HEADERS += \
    backend.h \
    config.h \
    congratswindow.h \
    frontend.h \
    game.h \
    gameoptions.h \
    gamestate.h \
    iabletonotify.h \
    mainwindow.h \
    newgamewindow.h \
    notificationbox.h \
    picture.h \
    result.h \
    resultstable.h \
    resultstablesaver.h \
    resultswindow.h \
    tile.h \
    tilestable.h

FORMS += \
    congratswindow.ui \
    mainwindow.ui \
    newgamewindow.ui \
    resultswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/spdlog/build/release/ -lspdlog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/spdlog/build/debug/ -lspdlog
else:unix: LIBS += -L$$PWD/spdlog/build/ -lspdlog

INCLUDEPATH += $$PWD/spdlog/include $$PWD/json/single_include $$PWD/CImg $$PWD/cxxopts/include
DEPENDPATH += $$PWD/spdlog/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/spdlog/build/release/libspdlog.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/spdlog/build/debug/libspdlog.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/spdlog/build/release/spdlog.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/spdlog/build/debug/spdlog.lib
else:unix: PRE_TARGETDEPS += $$PWD/spdlog/build/libspdlog.a
