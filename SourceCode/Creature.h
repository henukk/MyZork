#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include <string>

class Room;

class Creature : public Entity {
protected:
    Room* location;
    int life;
public:
    Creature(const std::string& name, const std::string& description, int life);
    virtual ~Creature();

    virtual void Tick();

    void setLocation(Room* location);
    bool isAlive() const;
    void takeDamage(int damage);
};

#endif
