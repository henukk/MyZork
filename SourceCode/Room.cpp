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
            cout << "You can see " << exit->getDestination()->getName()
                << " looking at " << exit->getDirectionString() << endl;
        }
    }

    // Items

    // Creatures
}
