#pragma once
#include "Animal.h"
class Wolf : public Animal
{
private:
	const int StartStrength = 9;
	const int StartInitiative = 5;
public:
	Wolf(int tura, World *newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
};