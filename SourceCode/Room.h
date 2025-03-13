#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Exit.h"

class Room : public Entity {
public:
    Room(const std::string& name, const std::string& description);
    ~Room();

    void Tick() override;

    void Look();

    std::list<Exit*> getExits();
};

#endif