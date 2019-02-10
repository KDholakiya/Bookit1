QT       += core gui widgets network

TARGET = BookIt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        bookit.cpp \
    movies.cpp \
    plays.cpp \
    sports.cpp \
    events.cpp \
    datavendor.cpp \
    eventhandler.cpp \
    info.cpp \
    readfile.cpp \
    paymentdialog.cpp \
    checkout.cpp \
    about.cpp \
    datareciever.cpp

HEADERS += \
        bookit.h \
    movies.h \
    plays.h \
    sports.h \
    events.h \
    datavendor.h \
    eventhandler.h \
    info.h \
    readfile.h \
    paymentdialog.h \
    checkout.h \
    about.h \
    datareciever.h

FORMS += \
        bookit.ui \
    movies.ui \
    plays.ui \
    sports.ui \
    events.ui \
    info.ui \
    paymentdialog.ui \
    checkout.ui \
    about.ui

win32 {
    RC_FILE = icon.rc
}

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    icon.rc \
    Bookit.exe.manifest
