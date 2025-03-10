#ifndef __World__
#define __World__

#include <vector>
#include <string>
#include <list>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

#define TICK_FREQUENCY 0.5f

//class Entity;
//class Player;

class World {
public:
	World();
	~World();

	void Tick(const vector<string>& commands);

private:
	clock_t tick_timer;
	//list<Entity*> entities;
	//Player* player;

	unordered_map<string, function<void(World&, const vector<string>&)>> commandMap;
	unordered_set<string> directionsSet;

	void GameLoop();
	void ParseCommand(const vector<string>& commands);

	//Commands
	void Help(const vector<string>& commands);
	void Move(const vector<string>& commands);
	void Look(const vector<string>& commands);
};

#endif //__World__
