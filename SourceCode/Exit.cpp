#include "Exit.h"

using namespace std;

Exit::Exit(Direction direction, Room* source, Room* destination) : Entity(Type::Exit, "","") {
    this->direction = direction;
    this->source = source;
    this->destination = destination;
}

Exit::~Exit() {}

Exit::Direction Exit::getDirection() {
    return direction;
}

Room* Exit::getSource() {
    return source;
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

void Exit::Tick() {
    
}