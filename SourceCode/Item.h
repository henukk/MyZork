#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"


class Item : public Entity {
private:
    short sizeContent;
    short size;
    bool takeable;
    bool sometimeTaked;

public:
    Item(const std::string& name, const std::string& description, const short size, const short sizeContent, const bool takeable);
    ~Item();

    void Tick() override;
    void Look(const std::string& pretext);
    void InventoryLook(const std::string& pretext);

    short getSizeContent();
    short getSize();
    bool getTakeable();
    void setSometimeTaked();
};

#endif