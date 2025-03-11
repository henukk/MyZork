#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(const string& name, const string& description, Room* location) : Creature(name, description, location) {}

Player::~Player() {}

void Player::Tick() {

};

void Player::Look() {
	location->Look();
}