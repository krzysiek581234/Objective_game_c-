#include "Wolf.h"

Wolf::Wolf(int tura, World* newWorld, Coordinates Pos):Animal(tura,newWorld,Pos)
{
	this->kod = 'W';
	this->initiative = this->StartInitiative;
	this->strength = this->StartStrength;
	this->type = Type::wolf;
}

Organism* Wolf::newChild(int turn, Coordinates Position)
{
	return new Wolf(turn, myWorld, Position);
}
