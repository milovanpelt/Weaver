// StoryStackLibraryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StoryStackLibrary.h"
#include <iostream>
int main()
{
    std::cout << "StoryStack Library Demo!\n\n";

    // Create Characters
    auto albus = StoryStack::CreateCharacter("Albus");
    auto minevra = StoryStack::CreateCharacter("Minerva");

    // Create scene
    auto scene_boyWhoLived = StoryStack::CreateScene("The Boy who lived");

    // Create dialogues
    StoryStack::AddDialogueToCharacter(scene_boyWhoLived, albus, StoryStack::DialogueTypes::Dialogue, "Hello Professor");
}