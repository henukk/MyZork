#include <iostream>

#include "Creature.h"

using namespace std;

Creature::Creature(const string& name, const string& description, Room* location) : Entity(Type::Creature, name, description) {
	this->location = location;
}

Creature::~Creature() {}

void Creature::Tick() {

};
