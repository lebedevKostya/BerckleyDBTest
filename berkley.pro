QT += core


TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Mydb.cpp \
    loader.cpp \
    reader.cpp

HEADERS += \
    Mydb.h \
    loader.h \
    reader.h \
    doctor.h

LIBS += -ldb_cxx

