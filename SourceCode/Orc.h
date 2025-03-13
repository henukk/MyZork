#ifndef ORC_H
#define ORC_H

#include "NPC.h"
#include "Player.h"

class Orc : public NPC {
private:
    const int TICKS_TO_MOVE = 10;
    const int TICKS_TO_ATTACK = 3;
    int waitCounter;
    Player* p;

    void Move();
    void Attack();
    
public:
    Orc(const std::string& name, const std::string& description, Player* p);
    ~Orc();

    void Tick() override;
    virtual void Talk();
};

#endif