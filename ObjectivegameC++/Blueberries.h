#pragma once
#include "Plant.h"
class Blueberries : public Plant
{
public:
	Blueberries(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
	Event* collision(Organism* attacker) override;
};