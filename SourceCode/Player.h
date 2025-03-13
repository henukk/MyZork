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
    void TakeFrom(const std::string& item, const std::string& from);
    void Drop(const std::string& item);
    void DropTo(const std::string& item, const std::string& to);
    void Inventory();
    void Use(const std::string& name, const std::string& on);
    void Talk(const std::string& name);
    void Attack(const std::string& objective, const std::string& weapon);


    std::list<Exit*> getExits();
};

#endif