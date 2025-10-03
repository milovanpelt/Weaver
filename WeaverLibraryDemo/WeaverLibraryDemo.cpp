// WeaverLibraryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WeaverLibrary.h"
int main()
{
    std::cout << "Weaver Library Demo!\n\n";

    // Create Characters
    auto albus = Weaver::CreateCharacter("Albus");
    auto minevra = Weaver::CreateCharacter("Minerva");

    // Create scene
    auto scene_boyWhoLived = Weaver::CreateScene("The Boy who lived");

    // Create dialogues
    Weaver::AddDialogueToCharacter(scene_boyWhoLived, albus, Weaver::DialogueTypes::Dialogue, "Hello Professor");
}