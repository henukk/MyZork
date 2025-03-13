#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"


class Item : public Entity {
private:
    short sizeContent;
    short size;

public:
    Item(const std::string& name, const short size, const short sizeContent);
    ~Item();

    void Tick() override;

    bool getSizeContent();
    bool getSize();
};

#endif