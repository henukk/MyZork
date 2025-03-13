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
	Entity* entity = this->location->getEntityByName(name);

	if (entity == nullptr) {
		cout << "Sorry I am not finding " << name << "." << endl;
	}
	else {
		Item* item = dynamic_cast<Item*>(entity);
		if (item) {
			if (item->getTakeable()) {
				this->location->removeEntityByName(name);
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


void Player::TakeFrom(const string& name, const string& from) {
	Entity* fromEntity = this->location->getEntityByName(from);

	if (fromEntity == nullptr) {
		cout << "Sorry I am not finding " << from << "." << endl;
	}
	else {
		Item* fromItem = dynamic_cast<Item*>(fromEntity);
		if (fromItem && fromItem->getSizeContent() > 0) {
			Entity* entity = fromEntity->getEntityByName(name);

			if (entity == nullptr) {
				cout << "Sorry I am not finding " << name << " inside of " << from << "." << endl;
			}
			else {
				Item* item = dynamic_cast<Item*>(entity);
				if (item) {
					if (item->getTakeable()) {
						fromEntity->removeEntityByName(name);
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
		else {
			cout << from << " seems that cannot contain anything." << endl;
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

void Player::DropTo(const string& name, const string& to) {
	Entity* toEntity = this->getEntityByName(to);
	if (toEntity == nullptr) {
		toEntity = this->location->getEntityByName(to);
	}

	if (toEntity == nullptr) {
		cout << "Sorry I am not finding " << to << "." << endl;
	}
	else {
		Item* toItem = dynamic_cast<Item*>(toEntity);
		if (toEntity) {
			Entity* entity = this->getEntityByName(name);

			if (entity == nullptr) {
				cout << "Sorry I am not finding " << name << "." << endl;
			}
			else {
				Item* item = dynamic_cast<Item*>(entity);

				if (item->getSize() <= toItem->getSizeContent()) {
					this->removeEntityByName(name);
					toEntity->addEntity(entity);
					cout << name << " dropped inside of " << to << "." << endl;
				}
				else {
					cout << "Seems that " << name << " cannot fit inside of " << to << "." << endl;
				}
			}
		}
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

