#include "Grass.h"

Grass::Grass(int tura, World* newWorld, Coordinates Pos) :Plant(tura, newWorld, Pos)
{
	this->kod = 'G';
	this->type = Type::grass;
}

Organism* Grass::newChild(int turn, Coordinates Position)
{
	return new Grass(turn, myWorld, Position);
}