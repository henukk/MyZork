#include <iostream>

#include "Creature.h"

using namespace std;

Creature::Creature(const string& name, const string& description, int life) : Entity(Type::Creature, name, description) {
	this->location = nullptr;
	this->life = life;
}

Creature::~Creature() {}

void Creature::Tick() {

};

void Creature::setLocation(Room* location) {
	this->location = location;
}

bool Creature::isAlive()const {
	return life > 0;
}

void Creature::takeDamage(int damage) {
	life -= damage;
}