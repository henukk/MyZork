#include <iostream>

#include "Dad.h"

using namespace std;

Dad::Dad(const std::string& name, const std::string& description) : NPC(name, description, 100) {
	waitCounter = 100;
}
Dad::~Dad() {

}

void Dad::Tick() {
    if (waitCounter == 1) description = "You see your dad anxiously pacing back and forth, his hands clenched into fists. His eyes dart around the room, and he mutters under his breath, clearly troubled by something.";
	if (waitCounter > 0) waitCounter--;

}
void Dad::Talk() {
    if (waitCounter > 0) {
        cout << "Hey son, I saw some orc footprints in the forest near the house. Go to the village and tell the guard. Take your sword from the barn; the keys are on the showcase. Hurry up!" << endl;
    }
    else {
        cout << "Where were you? I was looking for you! Listen, I saw some orc footprints in the forest near the house. Go to the village and tell the guard. Take your sword from the barn; the keys are on the showcase. Hurry up!" << endl;
    }
}
