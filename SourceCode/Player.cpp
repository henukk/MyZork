#include <iostream>

#include "Player.h"
#include "Item.h"

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


void Player::Take(const string& name) {
	Entity* entity = this->location->removeEntityByName(name);

	if (entity == nullptr) {
		cout << "Sorry I am not finding " << name << "." << endl;
	}
	else {
		Item * item =dynamic_cast<Item*>(entity);
		if (item) {
			if (item->getTakeable()) {
				this->addEntity(entity);
				item->setSometimeTaked();
				cout << name << " taked." << endl;
			}
			else {
				this->location->addEntity(entity);
				cout << name << " cannot be taked." << endl;
			}
		}
		else {
			this->location->addEntity(entity);
			cout << name << " cannot be taked." << endl;
		}
	}
}

void Player::Drop(const string& name) {
	Entity* entity = this->removeEntityByName(name);

	if (entity == nullptr) {
		cout << "Sorry I am not finding " << name << "." << endl;
	}
	else {
		this->location->addEntity(entity);
		cout << name << " dropped." << endl;
	}
}

void Player::Inventory() {
	if (this->contains.empty()) {
		cout << "Your inventory is empty, try to take something." << endl;
	}
	else {
		cout << "Inventory: " << endl;
		for (Entity* e : contains) {
			Item* item = dynamic_cast<Item*>(e);
			if (item) {
				item->InventoryLook("\t- ");
			}
		}
	}
}

