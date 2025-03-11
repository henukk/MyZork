#include <iostream>

#include "Room.h"

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
        if (e->getType() == Type::Exit) {
            ;
        }
    }

    // Items

    // Creatures
}
