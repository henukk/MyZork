#include <iostream>
#include <cstdlib>

#include "Orc.h"
#include "Exit.h"

using namespace std;

Orc::Orc(const std::string& name, const std::string& description, Player* p) : NPC(name, description, 20) {
    waitCounter = TICKS_TO_MOVE;
    this->p = p;
}
Orc::~Orc() {

}

void Orc::Move() {
    Room* current = getLocation();
    list<Exit*> exits = current->getExits();

    Exit::Direction direction = (rand() % 2) == 0 ? Exit::Direction::north : Exit::Direction::south;

    auto it = exits.begin();
    while (it != exits.end() and (*it)->getDirection() != direction) {
        ++it;
    }

    if (it != exits.end()) {
        current->removeEntity(this);
        Room* next = (*it)->getDestination();
        next->addEntity(this);
        setLocation(next);

        if (next == p->getLocation()) {
            p->Look();
            cout << "> ";
        }
    }

    waitCounter = TICKS_TO_MOVE;
}

void Orc::Attack() {
    if (p->isAlive()) {
        cout << endl << endl << "Orc attack fiercely." << endl << endl << "> ";
        int damage = rand() % 15;
        p->takeDamage(damage);
    }

    waitCounter = TICKS_TO_ATTACK;
}

void Orc::Tick() {
    if (isAlive() and waitCounter-- == 0) {
        if (p->getLocation() == location) {
            Attack();
        }
        else {
            Move();
        }
    }
}
void Orc::Talk() {
    int randomValue = rand() % 3;

    switch (randomValue) {
    case 0:
        std::cout << "Ghrum zhak'tar nogh!" << std::endl;
        break;
    case 1:
        std::cout << "Urrk varsh grom'ka!" << std::endl;
        break;
    case 2:
        std::cout << "Druum groth'kha norug." << std::endl;
        break;
    default:
        std::cout << "The orc grunts something unintelligible." << std::endl;
        break;
    }
}


void Orc::takeDamage(int damage) {
    life -= damage;
    if (!isAlive()) {
        description = "The orc's massive body lies still, its weapon slack in its grip. Scars of past battles remain, but its once-watchful eyes are now dull and empty, staring into nothingness.";

        cout << "Orc dies" << endl;
    }
}

