#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Item.h"

class Room;

class Exit : public Entity {
public:
    enum class Direction { north, south, east, west };

private:
    Direction direction;
    Room* destination;
    Item* closed;

public:
    Exit(const std::string& description, Direction direction, Room* destination);
    ~Exit();

    Direction getDirection();
    Room* getDestination();
    std::string getDirectionString() const;
    void setClosed(Item* key);
    bool isOpen();
    bool open(Item* key);

    void Tick() override;
};

#endif