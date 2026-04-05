QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CharacterCreationWindow.cpp \
    DialogueContainer.cpp \
    DialogueCreationWindow.cpp \
    WeaverController.cpp \
    WeaverWindow.cpp \
    main.cpp \
    ../../Core/WeaverLibrary/Source/DialogueManager.cpp \
    ../../Core/WeaverLibrary/Source/FileIO.cpp

HEADERS += \
    CharacterCreationWindow.h \
    DialogueContainer.h \
    DialogueCreationWindow.h \
    WeaverController.h \
    WeaverWindow.h

FORMS += \
    CharacterCreationWindow.ui \
    DialogueContainer.ui \
    DialogueCreationWindow.ui \
    WeaverWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Core/WeaverLibrary/x64/release/ -lWeaverLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Core/WeaverLibrary/x64/debug/ -lWeaverLibrary

CONFIG += precompile_header
PRECOMPILED_HEADER = $$PWD/../../Core/WeaverLibrary/pch.h

INCLUDEPATH += $$PWD/../../Core/WeaverLibrary
INCLUDEPATH += $$PWD/../../Core/WeaverLibrary/Include
INCLUDEPATH += $$PWD/../../Core/WeaverLibrary/External/JSON/nlohmann
INCLUDEPATH += $$PWD/../../Core/WeaverLibrary/External/UUID

DEPENDPATH += $$INCLUDEPATH

DEFINES += WEAVERLIBRARY_EXPORTS
