#include <iostream>

#include "Creature.h"

using namespace std;

Creature::Creature(const string& name, const string& description) : Entity(Type::Creature, name, description) {
	this->location = location;
}

Creature::~Creature() {}

void Creature::Tick() {

};

void Creature::setLocation(Room* location) {
	this->location = location;
}