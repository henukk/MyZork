#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Room.h"


class Player : public Creature {
public:
    Player(const std::string& name, const std::string& description);
    ~Player();

    void Tick() override;
    void Look();
    void Take(const std::string& item);
    void Drop(const std::string& item);
    void Inventory();

    std::list<Exit*> getExits();
};

#endif