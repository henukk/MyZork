#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"

class Room;


class Exit : public Entity {
public:
    enum class Direction { north, south, east, west };

private:
    Direction direction;
    Room* destination;

public:
    Exit(const std::string& description, Direction direction, Room* destination);
    ~Exit();

    Direction getDirection();
    Room* getSource();
    Room* getDestination();
    std::string getDirectionString() const;

    void Tick() override;
};

#endif