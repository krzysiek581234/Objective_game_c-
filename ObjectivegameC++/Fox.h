#pragma once
#include "Animal.h"
class Fox : public Animal
{
private:
	const int StartStrength = 3;
	const int StartInitiative = 7;
public:
	Fox(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int turn, Coordinates Pos) override;
	Event* action() override;
};