#include "Item.h"

using namespace std;

Item::Item(const std::string& name, const short size, const short sizeContent) : Entity(Type::Item, name, "") {
	this->size = size;
	this->sizeContent = sizeContent;
}

Item::~Item() {}

void Item::Tick() {

}

bool Item::getSizeContent() {
	return sizeContent;
}

bool Item::getSize() {
	return size;
}