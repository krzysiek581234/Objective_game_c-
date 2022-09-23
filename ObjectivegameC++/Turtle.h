#pragma once
#include "Animal.h"
class Turtle : public Animal
{
private:
	const int StartStrength = 2;
	const int StartInitiative = 1;
public:
	Turtle(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
	Event* action() override;
	Event* collision(Organism* attacker) override;
};