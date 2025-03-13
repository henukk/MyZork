#ifndef Dad_H
#define Dad_H

#include "NPC.h"

class Dad : public NPC {
private:
    int waitCounter;
public:
    Dad(const std::string& name, const std::string& description);
    ~Dad();

    void Tick() override;
    virtual void Talk();
};

#endif