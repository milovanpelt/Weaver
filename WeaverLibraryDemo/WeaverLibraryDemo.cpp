// WeaverLibraryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "WeaverLibrary.h"
#include "DialogueEntry.h"
int main()
{
    std::cout << "Weaver Library Demo!\n\n";

    // Creating json file with entries

    DialogueEntry entry1;
    entry1.speaker = "Alaster";
    entry1.lines = { "Hellow there", "How are you?" };

    DialogueEntry entry2;
    entry2.speaker = "James";
    entry2.lines = { "I am doing great", "Do you know where I can find the tea glasses?" };

    std::vector<DialogueEntry> testDialogue = { entry1, entry2 };

    const std::string filename = "dialogue.json";

    Weaver::FileIO::SaveDialogueToJSON(filename, testDialogue);

    // output data from file onto console

    std::vector<DialogueEntry> data = Weaver::FileIO::ReadDialogueFromJSON(filename);
    for (const auto& entry : data)
    {
        std::cout << "Speaker name: " << entry.speaker << "\n";

        for (size_t i = 0 ; i < entry.lines.size(); i++)
        {
            std::cout << "Line " << (i + 1) << " : " << entry.lines[i] << "\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
