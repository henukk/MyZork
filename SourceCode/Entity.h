#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>


class Entity {
public:
    enum class Type { Creature, Exit, Room, Item };

protected:
    Type type;
    std::string name;
    std::string description;
    std::list<Entity*> contains;

public:
    Entity(Type type, const std::string& name, const std::string& description);
    virtual ~Entity();

    virtual void Tick() = 0;

    Type getType();
    void addEntity(Entity* entity);
    Entity* removeEntity(Entity* entity);


    std::string& getName();
    std::string& getDescription();
    //vector<Entity*>& getContents();
};

#endif