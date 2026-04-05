#include "WeaverController.h"
#include "FileIO.h"

WeaverController::WeaverController(QObject *parent)
    : QObject{parent}
{}

void WeaverController::on_SavingDialogueRequested(const std::string& filename)
{
    std::cout << "[Weaver Controller]: Dialogue Saving Requested" << std::endl;
    Weaver::FileIO::SaveDialogueToJSON(filename, Weaver::GetCharacters(), Weaver::GetScenes());
}

void WeaverController::on_CreateDialogueRequested(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue)
{
    std::cout << "[Weaver Controller]: Dialogue Creation Requested" << std::endl;
    Weaver::AddDialogueToCharacter(sceneID, speakerID, type, dialogue);
    emit WeaverController::DialogueCreated(speakerID, type, dialogue);
}

void WeaverController::on_CharacterCreatedRequested(const std::string& name)
{
    std::cout << "[Weaver Controller]: Character Creation Requested" << std::endl;
    Weaver::CreateCharacter(name);
    emit WeaverController::CharacterCreated(name);
}
