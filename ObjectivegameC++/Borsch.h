#pragma once
#include "Plant.h"
class Borsch : public Plant
{
public:
	Borsch(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
	Event* collision(Organism* attacker) override;
	Event* action() override;
};
