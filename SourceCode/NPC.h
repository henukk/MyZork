#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class NPC : public Creature {
public:
    NPC(const std::string& name, const std::string& description, int live);
    ~NPC();

    void Tick() override;
    virtual void Talk();
};

#endif