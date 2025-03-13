#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(const std::string& name, const string& description, const short size, const short sizeContent, const bool takeable) : Entity(Type::Item, name, description) {
	this->size = size;
	this->sizeContent = sizeContent;
	this->takeable = takeable;

	sometimeTaked = false;
}

Item::~Item() {}

void Item::Tick() {

}

void Item::Look(const string& pretext) {
	if (sometimeTaked) {
		cout << pretext << "Dropped " << name << '.' << endl;
	}
	else {
		cout << pretext << description << endl;
	}

	if (sizeContent > 0) {
		for (Entity* e : contains) {
			Item* item = dynamic_cast<Item*>(e);
			item->Look(pretext + "\t- ");
		}
	}
}

void Item::InventoryLook(const string& pretext) {
	if (sometimeTaked) {
		cout << pretext << name << '.' << endl;
	}
	else {
		cout << pretext << description << endl;
	}

	if (sizeContent > 0) {
		for (Entity* e : contains) {
			Item* item = dynamic_cast<Item*>(e);
			item->Look(pretext + "\t- ");
		}
	}
}

bool Item::getSizeContent() {
	return sizeContent;
}

bool Item::getSize() {
	return size;
}

void Item::setSometimeTaked() {
	sometimeTaked = true;
}

bool Item::getTakeable() {
	return takeable;
}