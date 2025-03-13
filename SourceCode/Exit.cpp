#include "Exit.h"

using namespace std;

Exit::Exit(const std::string& name, const std::string& description, Direction direction, Room* destination) : Entity(Type::Exit, name, description) {
    this->direction = direction;
    this->destination = destination;

    this->closed = nullptr;
}

Exit::~Exit() {}

Exit::Direction Exit::getDirection() {
    return direction;
}

Room* Exit::getDestination() {
    return destination;
}

string Exit::getDirectionString() const {
    switch (direction) {
        case Direction::north: return "north";
        case Direction::south: return "south";
        case Direction::east: return "east";
        case Direction::west: return "west";
    }
    return "unknown";
}

void Exit::setClosed(Item* key) {
    closed = key;
}

bool Exit::open(Item* key) {
    if (closed == key) {
        closed = nullptr;
        return true;
    }
    return false;
}

bool Exit::isOpen() {
    return closed == nullptr;
}

void Exit::Tick() {
    
}