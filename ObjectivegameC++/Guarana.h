#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
	Event* collision(Organism* attacker) override;
};