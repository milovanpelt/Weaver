#include "StoryStackController.h"
#include "FileIO.h"

StoryStackController::StoryStackController(QObject *parent)
    : QObject{parent}
{}

void StoryStackController::on_SavingDialogueRequested(const std::string& filename)
{
    std::cout << "[StoryStack Controller]: Dialogue Saving Requested" << std::endl;
    StoryStack::FileIO::SaveDialogueToJSON(filename, StoryStack::GetCharacters(), StoryStack::GetScenes());
}

void StoryStackController::on_CreateDialogueRequested(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, StoryStack::DialogueTypes type, const std::string& dialogue)
{
    std::cout << "[StoryStack Controller]: Dialogue Creation Requested" << std::endl;
    StoryStack::AddDialogueToCharacter(sceneID, speakerID, type, dialogue);
    emit StoryStackController::DialogueCreated(speakerID, type, dialogue);
}

void StoryStackController::on_CharacterCreatedRequested(const std::string& name)
{
    std::cout << "[StoryStack Controller]: Character Creation Requested" << std::endl;
    StoryStack::CreateCharacter(name);
    emit StoryStackController::CharacterCreated(name);
}
