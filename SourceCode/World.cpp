#include "World.h"
#include <iostream>

using namespace std;

World::World() {
	tick_timer = clock();

	commandMap = {
		{"help", [this](World& world, const vector<string>& args) { world.Help(args); }},
		{"move", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"go", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"look", [this](World& world, const vector<string>& args) { world.Look(args); }}
	};

	directionsSet = { "north", "south", "west", "east" };

}

World::~World() {
	commandMap.clear();
	directionsSet.clear();
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
			cout << "Move..." << endl;
		}
	}

	void World::Look(const vector<string>& commands) {
		if (commands.size() != 1) {
			cout << "Sorry I have only understood '" << commands[0] << "'." << endl;
		} else {
			cout << "Look..." << endl;
		}
	}

#pragma endregion