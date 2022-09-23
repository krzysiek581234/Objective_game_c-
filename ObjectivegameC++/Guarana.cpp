#include "Guarana.h"

Guarana::Guarana(int tura, World* newWorld, Coordinates Pos) :Plant(tura, newWorld, Pos)
{
	this->kod = '+';
	this->type = Type::guarana;
}

Organism* Guarana::newChild(int turn, Coordinates Position)
{
	return new Guarana(turn, myWorld, Position);
}
Event* Guarana::collision(Organism* attacker)
{
	attacker->addStrength(3);
	return  new Event(attacker->getPosition(), Call::kill, this->position);
}