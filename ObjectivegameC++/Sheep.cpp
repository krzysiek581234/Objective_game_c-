#include "Sheep.h"

Sheep::Sheep(int tura, World* newWorld, Coordinates Pos) :Animal(tura, newWorld, Pos)
{
	this->kod = 'S';
	this->initiative = this->StartInitiative;
	this->strength = this->StartStrength;
	this->type = Type::sheep;
}

Organism* Sheep::newChild(int turn, Coordinates Position)
{
	return new Sheep(turn, myWorld, Position);
}
