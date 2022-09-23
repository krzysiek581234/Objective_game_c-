#include "Dandelion.h"

Dandelion::Dandelion(int tura, World* newWorld, Coordinates Pos) :Plant(tura, newWorld, Pos)
{
	this->kod = '#';
	this->seeds = 3;
	this->type = Type::dandelion;
}

Organism* Dandelion::newChild(int turn, Coordinates Position)
{
	return new Dandelion(turn, myWorld, Position);
}