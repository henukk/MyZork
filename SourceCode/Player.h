#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Room.h"


class Player : public Creature {
public:
    Player(const std::string& name, const std::string& description, Room* location);
    ~Player();

    void Tick() override;
    void Look();
};

#endif