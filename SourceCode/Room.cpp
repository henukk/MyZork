#include <iostream>

#include "Room.h"
#include "Exit.h"

using namespace std;

Room::Room(const string& name, const string& description) : Entity(Type::Room, name, description) {}

Room::~Room() {

}

void Room::Tick() {
    ;
}

void Room::Look() {
    cout << name << endl;
    cout << description << endl;

    for (Entity* e : contains) {
        Exit* exit = dynamic_cast<Exit*>(e);
        if (exit) {
            string desc = exit->getDescription();
            if (desc != "") cout << desc << endl;
        }
    }

    // Items

    // Creatures
}


vector<Exit*> Room::getExits() {
    vector<Exit*> result = vector<Exit*>();

    for (Entity* e : contains) {
        Exit* exit = dynamic_cast<Exit*>(e);
        if (exit) {
            result.push_back(exit);
        }
    }

    return result;
}