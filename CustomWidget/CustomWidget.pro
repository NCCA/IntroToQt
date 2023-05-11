CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(mat4plugin)
TEMPLATE    = lib

HEADERS     = mat4plugin.h
SOURCES     = mat4plugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(mat4.pri)
