QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    weaverwindow.cpp \
    ../WeaverLibrary/Source/FileIO.cpp

HEADERS += \
    weaverwindow.h

FORMS += \
    weaverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../WeaverLibrary/x64/release/ -lWeaverLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../WeaverLibrary/x64/debug/ -lWeaverLibrary

CONFIG += precompile_header
PRECOMPILED_HEADER = $$PWD/../WeaverLibrary/pch.h

INCLUDEPATH += $$PWD/../WeaverLibrary
INCLUDEPATH += $$PWD/../WeaverLibrary/Include
INCLUDEPATH += $$PWD/../WeaverLibrary/External/JSON/nlohmann

DEPENDPATH += $$INCLUDEPATH

DEFINES += WEAVERLIBRARY_EXPORTS
