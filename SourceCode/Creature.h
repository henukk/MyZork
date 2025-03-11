#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"

class Creature : public Entity {
protected:
    Room* location;

public:
    Creature(const std::string& name, const std::string& description, Room* location);
    ~Creature();

    void Tick() override;
};

#endif