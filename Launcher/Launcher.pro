# -------------------------------------------------
# Project created by QtCreator 2009-11-05T22:11:46
# -------------------------------------------------
QT += core \
    	gui \
      widgets

TARGET=Launcher
# this is where we want to put the intermediate build files ( .o)
OBJECTS_DIR=obj/
MOC_DIR=moc/
SOURCES += $$PWD/src/main.cpp \
           $$PWD/src/MainWindow.cpp \
           $$PWD/src/DebugWindow.cpp \
           $$PWD/src/AddItem.cpp
OTHER_FILES+=launcher.json
INCLUDEPATH += include/

HEADERS += $$PWD/include/MainWindow.h \
          $$PWD/include/DebugWindow.h \
          $$PWD/include/AddItem.h

CONFIG -= app_bundle
CONFIG +=c++11
DEPENDPATH+=include

FORMS += \
    ui/DebugWindow.ui \
    ui/AddItem.ui

RESOURCES += \
    src/resources.qrc
