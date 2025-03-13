#include "Entity.h"

using namespace std;

Entity::Entity(Type type, const string& name, const string& description) {
    this->type = type;
    this->name = name;
    this->description = description;
    this->contains = list<Entity*>();
}

Entity::~Entity() {}

Entity::Type Entity::getType() {
    return type;
}


void Entity::addEntity(Entity* entity) {
    contains.push_back(entity);
}


Entity* Entity::removeEntity(Entity* entity) {
    auto it = contains.begin();

    while (it != contains.end() && (*it)->getName() != entity->getName()) {
        ++it;
    }

    if (it != contains.end()) {
        Entity* removedEntity = *it; 
        contains.erase(it);
        return removedEntity;
    }

    return nullptr;
}


Entity* Entity::removeEntityByName(const std::string& name) {
    auto it = contains.begin();

    while (it != contains.end() && (*it)->getName() != name) {
        ++it;
    }

    if (it != contains.end()) {
        Entity* removedEntity = *it;
        contains.erase(it);
        return removedEntity;
    }

    return nullptr;
}


string& Entity::getName() {
    return name;
}

string& Entity::getDescription() {
    return description;
}

/*
vector<Entity*>& Entity::getContents() {
    return contains;
}
*/