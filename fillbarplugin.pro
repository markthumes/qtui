QT          += widgets uiplugin

CONFIG      += plugin
TEMPLATE    = lib

TARGET = $$qtLibraryTarget($$TARGET)

target.path = /home/mark/Qt5.7.0/Tools/QtCreator/lib/Qt/plugins/designer
INSTALLS += target

HEADERS     = fillbar.h \
              fillbarplugin.h
SOURCES     = fillbar.cpp \
              fillbarplugin.cpp
