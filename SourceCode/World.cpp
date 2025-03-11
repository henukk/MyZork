#include <iostream>

#include "World.h"
#include "Room.h"
#include "Exit.h"


using namespace std;

World::World() {
	tick_timer = clock();

	commandMap = {
		{"help", [this](World& world, const vector<string>& args) { world.Help(args); }},
		{"move", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"go", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"look", [this](World& world, const vector<string>& args) { world.Look(args); }}
	};

	Room* outsideHouse = new Room("Outside house", "You are in front of your house, you can see your dad on the Kitchen by the window.");
	entities.push_back(outsideHouse);

	Room* insideHouse = new Room("Inside the house", "You are inside your house there is a red carpet on the floor centered on the room, above there is the table where usually have meals with your parent.");
	entities.push_back(insideHouse);

	Room* forest2 = new Room("Forest", "You are in the woods. Having talls trees in all directions.");
	entities.push_back(forest2);

	Exit* enterHouse = new Exit(Exit::Direction::west, outsideHouse, insideHouse);
	outsideHouse->AddEntity(enterHouse);
	entities.push_back(enterHouse);
	
	Exit* exitHouse = new Exit(Exit::Direction::east, insideHouse, outsideHouse);
	insideHouse->AddEntity(exitHouse);
	entities.push_back(exitHouse);


	player = new Player("MainPlayer", "");
	player->setLocation(outsideHouse);

	entities.push_back(player);
}

World::~World() {
	commandMap.clear();
	//clean memory
	//save data
}

void World::GameLoop() {
	clock_t now = clock();

	if ((now - tick_timer) / CLOCKS_PER_SEC > TICK_FREQUENCY) {
		/*
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			(*it)->Tick();		
		*/

		tick_timer = now;
	}
}

void World::ParseCommand(const vector<string>& commands) {
	auto it = commandMap.find(commands[0]);
	if (it != commandMap.end())
		it->second(*this, commands);
	else
		cout << "Sorry I don't know what are you trying to do" << endl;
}


void World::Tick(const vector<string> & commands) {
	if (commands.size() != 0) {
		cout << endl;
		ParseCommand(commands);
		cout << endl;
	}

	GameLoop();
}


#pragma region Commands

	void World::Help(const vector<string>& commands) {
		if (commands.size() != 1) {
			cout << "Sorry I have only understood '" << commands[0] << "'." << endl;
		} else {
			cout << "Help..." << endl;
		}
	}

	void World::Move(const vector<string>& commands) {
		if (commands.size() != 2) {
			cout << "Sorry I have only understood '" << commands[0] << "'." << endl;
		} else {
			vector<Exit*> exits = player->getExits();
			int n = exits.size(), i = 0;
			while (i < n and exits[i]->getDirectionString() != commands[1]) {
				++i;
			}

			if (i < n) {
				player->setLocation(exits[i]->getDestination());
				player->Look();
			} else {
				cout << "Go in that direction seems to be impossible." << endl;
			}

		}
	}

	void World::Look(const vector<string>& commands) {
		if (commands.size() != 1) {
			cout << "Sorry I have only understood '" << commands[0] << "'." << endl;
		} else {
			player->Look();
		}
	}

#pragma endregion