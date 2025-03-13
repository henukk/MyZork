#ifndef __WORLD__
#define __WORLD__

#include <vector>
#include <string>
#include <list>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <functional>

#include "Player.h"
#include "Entity.h"
#include "Orc.h"
#include "Room.h"

#define TICK_FREQUENCY 0.5f

class World {
public:
	World();
	~World();

	void Tick(const std::vector<std::string>& commands);
	bool End();

private:
	std::clock_t tick_timer;
	Player* player;
	Orc* orc;
	Room* winRoom;
	Room* loseRoom;
	std::list<Entity*> entities;

	std::unordered_map<std::string, std::function<void(World&, const std::vector<std::string>&)>> commandMap;

	void GameLoop();
	void ParseCommand(const std::vector<std::string>& commands);

	// Commands
	void Help(const std::vector<std::string>& commands);
	void Move(const std::vector<std::string>& commands);
	void Look(const std::vector<std::string>& commands);
	void Take(const std::vector<std::string>& commands);
	void Drop(const std::vector<std::string>& commands);
	void Inventory(const std::vector<std::string>& commands);
	void Use(const std::vector<std::string>& commands);
	void Talk(const std::vector<std::string>& commands);
	void Attack(const std::vector<std::string>& commands);

	
};

#endif //__WORLD__

