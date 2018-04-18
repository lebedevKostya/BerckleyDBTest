QT += core


TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Mydb.cpp \
    reader.cpp \
    test.cpp

HEADERS += \
    Mydb.h \
    dataset.h

LIBS += -ldb_cxx

