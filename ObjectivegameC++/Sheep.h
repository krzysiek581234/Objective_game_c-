#pragma once
#include "Animal.h"
class Sheep : public Animal
{
private:
	const int StartStrength =4;
	const int StartInitiative =4;
public:
	Sheep(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
};