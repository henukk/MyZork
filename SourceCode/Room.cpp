#include <iostream>

#include "Room.h"
#include "Exit.h"
#include "Item.h"

using namespace std;

Room::Room(const string& name, const string& description) : Entity(Type::Room, name, description) {}

Room::~Room() {

}

void Room::Tick() {
    ;
}

void Room::Look() {
    static bool spaced = false;

    cout << name << endl;
    cout << description << endl;

    for (Entity* e : contains) {
        Exit* exit = dynamic_cast<Exit*>(e);
        if (exit) {
            if (!spaced) cout << endl;
            spaced = true;
            string desc = exit->getDescription();
            if (desc != "") cout << desc << endl;
        }
    }
    spaced = false;

    // Items

    for (Entity* e : contains) {
        Item* item = dynamic_cast<Item*>(e);
        if (item) {
            if (!spaced) cout << endl;
            spaced = true;
            item->Look("");
        }
    }
    spaced = false;

    // Creatures
}


list<Exit*> Room::getExits() {
    list<Exit*> result = list<Exit*>();

    for (Entity* e : contains) {
        Exit* exit = dynamic_cast<Exit*>(e);
        if (exit) {
            result.push_back(exit);
        }
    }

    return result;
}