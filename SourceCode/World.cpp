#include <iostream>

#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"


using namespace std;

World::World() {
	tick_timer = clock();

	commandMap = {
		{"help", [this](World& world, const vector<string>& args) { world.Help(args); }},
		{"move", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"go", [this](World& world, const vector<string>& args) { world.Move(args); }},
		{"look", [this](World& world, const vector<string>& args) { world.Look(args); }}
	};

#pragma region Rooms
	Room* house = new Room("The House in the Woods", "A modest wooden house, its walls worn by time and weather. The scent of old wood and lingering smoke from the hearth fills the air. A sturdy table sits near the fireplace, and a creaking chair rests beside it. Shadows dance along the walls, flickering with the dim candlelight.");
	entities.push_back(house);

	Room* infrontOfHouse = new Room("Infront of the house", "The ground is well-trodden, marked by years of toil and practice. An old stump, its surface scarred by countless blade strikes, stands as a silent witness to your training. Nearby, logs lie in neat stacks, their fresh scent mixing with the crisp forest air. The woods loom beyond, whispering secrets in the wind.");
	entities.push_back(infrontOfHouse);

	Room* barn = new Room("Barn", "The barn leans slightly to one side, its aged planks groaning in protest against the weight of years. A rusty lantern sways from a beam, casting trembling light upon scattered tools, bales of hay, and forgotten remnants of past labors. The scent of damp straw and aged leather lingers.");
	entities.push_back(barn);

	Room* forest1 = new Room("Forest 1", "The trees stand tall and twisted, their roots gripping the earth like ancient fingers. The air is thick with the scent of moss and damp leaves. In the distance, birds call out, their songs blending with the gentle rustling of the wind through the branches.");
	entities.push_back(forest1);

	Room* forest2 = new Room("Forest 2", "The path narrows, winding between trunks draped in ivy. Sunlight filters through the dense canopy, casting golden patches on the mossy ground. A distant rustling in the underbrush hints at unseen creatures moving just beyond sight.");
	entities.push_back(forest2);

	Room* forest3 = new Room("Forest 3", "The trees here are massive, their towering branches weaving together to form a tangled ceiling. The air is cool, thick with the scent of wood and resin. Strange carvings mark a few trunks, their meanings lost to time.");
	entities.push_back(forest3);

	Room* westOfTheBridge = new Room("West of the bridge", "The path leads to the edge of a wide river, its waters rushing swiftly below. The sound of flowing water fills the air, mingling with the rustling leaves. Across the river, the faint outline of buildings can be seen in the distance, but the way forward remains uncertain.");
	entities.push_back(westOfTheBridge);

	Room* credits = new Room("THE END", "You've completed the game, i hope you enjoy it!\n\nhenuk");
	entities.push_back(credits);
#pragma endregion

#pragma region Exits
	//House
	Exit* exitHouse = new Exit("The door opens to the familiar yard, where the ground is worn from years of work and training. The path east leads back outside.", Exit::Direction::east, infrontOfHouse);
	house->addEntity(exitHouse);
	entities.push_back(exitHouse);

	//Infront
	Exit* enterHouse = new Exit("A well-trodden dirt path leads west to the wooden steps of your home.", Exit::Direction::west, house);
	infrontOfHouse->addEntity(enterHouse);
	entities.push_back(enterHouse);

	Exit* enterBarn = new Exit("A narrow trail, littered with stray wood chips and hay, leads north to the leaning barn", Exit::Direction::north, barn);
	infrontOfHouse->addEntity(enterBarn);
	entities.push_back(enterBarn);

	Exit* houseToForest1 = new Exit("The trees thicken ahead, their towering trunks marking the forest's edge. The path east vanishes into the woods.", Exit::Direction::east, forest1);
	infrontOfHouse->addEntity(houseToForest1);
	entities.push_back(houseToForest1);

	//Barn
	Exit* exitBarn = new Exit("The open yard and your home lie south, just beyond the well-worn path.", Exit::Direction::south, infrontOfHouse);
	barn->addEntity(exitBarn);
	entities.push_back(exitBarn);

	//Forest 1
	Exit* toInfront = new Exit("", Exit::Direction::west, infrontOfHouse);
	forest1->addEntity(toInfront);
	entities.push_back(toInfront);

	Exit* toWestOfBridge = new Exit("", Exit::Direction::east, westOfTheBridge);
	forest1->addEntity(toWestOfBridge);
	entities.push_back(toWestOfBridge);

	Exit* forest1Toforest2 = new Exit("Trees stretch endlessly in every direction, their tangled roots and dense foliage making every path uncertain. Any direction could lead deeper into the wilderness.", Exit::Direction::north, forest2);
	forest1->addEntity(forest1Toforest2);
	entities.push_back(forest1Toforest2);

	Exit* forest1Toforest3 = new Exit("", Exit::Direction::south, forest3);
	forest1->addEntity(forest1Toforest3);
	entities.push_back(forest1Toforest3);

	//Forest 2
	Exit* forest2N = new Exit("Trees stretch endlessly in every direction, their tangled roots and dense foliage making every path uncertain. Any direction could lead deeper into the wilderness.", Exit::Direction::north, forest3);
	forest2->addEntity(forest2N);
	entities.push_back(forest2N);

	Exit* forest2S = new Exit("", Exit::Direction::south, forest1);
	forest2->addEntity(forest2S);
	entities.push_back(forest2S);

	Exit* forest2E = new Exit("", Exit::Direction::west, forest2);
	forest2->addEntity(forest2E);
	entities.push_back(forest2E);

	Exit* forest2W = new Exit("", Exit::Direction::east, forest2);
	forest2->addEntity(forest2W);
	entities.push_back(forest2W);

	//Forest 3
	Exit* forest3N = new Exit("Trees stretch endlessly in every direction, their tangled roots and dense foliage making every path uncertain. Any direction could lead deeper into the wilderness.", Exit::Direction::north, forest1);
	forest3->addEntity(forest3N);
	entities.push_back(forest3N);

	Exit* forest3S = new Exit("", Exit::Direction::south, forest2);
	forest3->addEntity(forest3S);
	entities.push_back(forest3S);

	Exit* forest3E = new Exit("", Exit::Direction::west, forest3);
	forest3->addEntity(forest3E);
	entities.push_back(forest3E);

	Exit* forest3W = new Exit("", Exit::Direction::east, forest3);
	forest3->addEntity(forest3W);
	entities.push_back(forest3W);

	//West of bridge
	Exit* bridgeToForest1 = new Exit("The river fades behind as the dense forest closes in. The path west vanishes beneath towering trees and tangled undergrowth.", Exit::Direction::west, forest1);
	westOfTheBridge->addEntity(bridgeToForest1);
	entities.push_back(bridgeToForest1);

	Exit* bridgeToCredits = new Exit("The land narrows toward the river, where the bridge stands as the only way forward. The path east leads toward it.", Exit::Direction::east, credits);
	westOfTheBridge->addEntity(bridgeToCredits);
	entities.push_back(bridgeToCredits);

#pragma endregion

#pragma region Items
	//house
	Item* showCase = new Item("show case", 10, 2);
	house->addEntity(showCase);
	entities.push_back(showCase);

	Item* bag = new Item("old bag", 10, 2);
	house->addEntity(bag);
	entities.push_back(bag);

	Item* barnKey = new Item("barn key", 1, 0);
	house->addEntity(barnKey);
	entities.push_back(barnKey);

	Item* cloveGarlic = new Item("clove of garlic", 1, 0);
	house->addEntity(cloveGarlic);
	entities.push_back(cloveGarlic);

	//house
	Item* axe = new Item("old rusty axe", 10, 0);
	infrontOfHouse->addEntity(axe);
	entities.push_back(axe);

	//barn
	Item* ironSword = new Item("an iron sword", 10, 0);
	barn->addEntity(ironSword);
	entities.push_back(ironSword);



#pragma endregion

	player = new Player("MainPlayer", "");
	player->setLocation(infrontOfHouse);


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
			list<Exit*> exits = player->getExits();
			auto it = exits.begin();

			while (it != exits.end() && (*it)->getDirectionString() != commands[1]) {
				++it;
			}

			if (it != exits.end()) {
				player->setLocation((*it)->getDestination());
				player->Look();
			}
			else {
				cout << "Going in that direction seems to be impossible." << endl;
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