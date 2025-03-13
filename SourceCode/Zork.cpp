#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>

#include "World.h"

using namespace std;

#define RELEASE 2

void PrepareCommands(string& playerInput, vector<string>& commands) {
    int a = 0, size = playerInput.size();

    transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::tolower);

    for (int i = 0; i < size; ++i) {
        if (playerInput[i] == ' ') {
            if (a != i) {
                commands.push_back(playerInput.substr(a, i - a));
            }
            a = i + 1;
        }
    }

    if (a < size) {
        commands.push_back(playerInput.substr(a, size - a));
    }
}


int main() {
    cout << "MY ZORK" << endl << endl;
    cout << "WELCOME to MY ZORK" << endl;
    cout << "Release " << RELEASE << " / By henuk" << endl;
    cout << "----------------" << endl;

    char c;
    string playerInput = "";
    vector<string> commands = vector<string>();
    commands.push_back("look");

    World* world = new World();

    while (1) {
        if (_kbhit()) {
            c = _getch();
            if (c == '\r') {
                PrepareCommands(playerInput, commands);
            } else if (c == '\b') {
                if (playerInput.size() > 0) {
                    playerInput.pop_back();
                    cout << '\b';
                    cout << ' ';
                    cout << '\b';
                }
            } else {
                playerInput += c;
                cout << c;
            }
        }


        if (commands.size() > 0 and (commands[0] == "quit" or commands[0] == "exit")) break;

        world->Tick(commands);

        if (commands.size() != 0) {
            commands.clear();
            playerInput = "";
            cout << "> ";
        }
    }

    delete world;

    cout << endl << "Thank you for playing, I hope you enjoy it." << endl;
    Sleep(1500);
}