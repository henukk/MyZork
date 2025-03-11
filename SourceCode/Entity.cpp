#include "Entity.h"

using namespace std;

Entity::Entity(Type type, const string& name, const string& description) {
    this->type = type;
    this->name = name;
    this->description = description;
    this->contains = vector<Entity*>();
}

Entity::~Entity() {}

Entity::Type Entity::getType() {
    return type;
}


void Entity::AddEntity(Entity* entity) {
    contains.push_back(entity);
}


/*
string& Entity::getName() {
    return name;
}

string& Entity::getDescription() {
    return description;
}

vector<Entity*>& Entity::getContents() {
    return contains;
}
*/