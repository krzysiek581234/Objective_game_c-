#pragma once
#include "Animal.h"
class Antelope : public Animal
{
private:
	const int StartStrength = 4;
	const int StartInitiative = 4;
public:
	Antelope(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
	Event* action() override;
	Event* collision(Organism* attacker) override;
};