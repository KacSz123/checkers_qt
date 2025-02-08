QT       += core gui #qtsvg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += inc/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/checkersqueen.cpp \
    src/pawn.cpp \
    src/player.cpp \
    src/checkersboard.cpp \
    src/board_widget.cpp \
    src/checkerspiece.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    inc/checkersqueen.hh \
    inc/pawn.hh \
    inc/player.hh \
    inc/board_widget.hh \
    inc/checkersboard.hh \
    inc/checkerspiece.hh \
    inc/mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    checkers_qt_en_GB.ts
#CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
