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
    StoryStackController.cpp \
    StoryStackWindow.cpp \
    main.cpp \
    ../../Core/StoryStackLibrary/Source/DialogueManager.cpp \
    ../../Core/StoryStackLibrary/Source/FileIO.cpp

HEADERS += \
    CharacterCreationWindow.h \
    DialogueContainer.h \
    DialogueCreationWindow.h \
    StoryStackController.h \
    StoryStackWindow.h

FORMS += \
    CharacterCreationWindow.ui \
    DialogueContainer.ui \
    DialogueCreationWindow.ui \
    StoryStackWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Core/StoryStackLibrary/x64/release/ -lStoryStackLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Core/StoryStackLibrary/x64/debug/ -lStoryStackLibrary

CONFIG += precompile_header
PRECOMPILED_HEADER = $$PWD/../../Core/StoryStackLibrary/pch.h

INCLUDEPATH += $$PWD/../../Core/StoryStackLibrary
INCLUDEPATH += $$PWD/../../Core/StoryStackLibrary/Include
INCLUDEPATH += $$PWD/../../Core/StoryStackLibrary/External/JSON/nlohmann
INCLUDEPATH += $$PWD/../../Core/StoryStackLibrary/External/UUID

DEPENDPATH += $$INCLUDEPATH

DEFINES += STORYSTACKLIBRARY_EXPORTS
