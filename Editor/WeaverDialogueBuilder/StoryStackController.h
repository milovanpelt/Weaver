#ifndef STORYSTACKCONTROLLER_H
#define STORYSTACKCONTROLLER_H

#include <QObject>
#include "DialogueManager.h"
#include "uuid_v4.h"

class StoryStackController : public QObject
{
    Q_OBJECT
public:
    explicit StoryStackController(QObject *parent = nullptr);
signals:
    void CharacterCreated(const std::string& name);
    void DialogueCreated(UUIDv4::UUID speakerID, StoryStack::DialogueTypes type, const std::string& dialogue);
public slots:
    void on_SavingDialogueRequested(const std::string& filename);
    void on_CreateDialogueRequested(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, StoryStack::DialogueTypes type, const std::string& dialogue);
    void on_CharacterCreatedRequested(const std::string& name);
};

#endif // STORYSTACKCONTROLLER_H
