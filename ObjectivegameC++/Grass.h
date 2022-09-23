#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
};