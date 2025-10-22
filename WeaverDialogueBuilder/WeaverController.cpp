#include "WeaverController.h"

WeaverController::WeaverController(QObject *parent)
    : QObject{parent}
{}

void WeaverController::on_SavingDialogueRequested(const std::string& filename)
{}

void WeaverController::on_CreateDialogueRequested(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue)
{}

void WeaverController::on_CharacterCreatedRequested(const std::string& name)
{}
