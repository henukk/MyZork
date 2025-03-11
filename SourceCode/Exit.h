#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Room.h"


class Exit : public Entity {
public:
    enum class Direction { north, south, east, west };

private:
    Direction direction;
    Room* source;
    Room* destination;

public:
    Exit(Direction direction, Room* source, Room* destination);
    ~Exit();

    Direction getDirection();
    Room* getSource();
    Room* getDestination();
    std::string getDirectionString() const;

    void Tick() override;
};

#endif