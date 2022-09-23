#pragma once
#include "Plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int tura, Coordinates Pos) override;
};