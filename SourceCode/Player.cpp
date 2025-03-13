#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(const string& name, const string& description) : Creature(name, description) {}

Player::~Player() {}

void Player::Tick() {

};

void Player::Look() {
	location->Look();
}

list<Exit*> Player::getExits() {
	return this->location->getExits();
}