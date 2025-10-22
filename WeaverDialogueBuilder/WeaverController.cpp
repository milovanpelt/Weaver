#include "WeaverController.h"
#include "FileIO.h"

WeaverController::WeaverController(QObject *parent)
    : QObject{parent}
{}

void WeaverController::on_SavingDialogueRequested(const std::string& filename)
{
    Weaver::FileIO::SaveDialogueToJSON(filename, Weaver::GetCharacters(), Weaver::GetScenes());
}

void WeaverController::on_CreateDialogueRequested(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue)
{
    Weaver::AddDialogueToCharacter(sceneID, speakerID, type, dialogue);
    emit WeaverController::DialogueCreated(type);
}

void WeaverController::on_CharacterCreatedRequested(const std::string& name)
{
    Weaver::CreateCharacter(name);
    emit WeaverController::CharacterCreated(name);
}
