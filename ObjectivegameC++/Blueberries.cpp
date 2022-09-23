#include "Blueberries.h"
Blueberries::Blueberries(int tura, World* newWorld, Coordinates Pos) :Plant(tura, newWorld, Pos)
{
	this->kod = 'B';
	this->type = Type::dandelion;
	this->strength = 99;
}

Organism* Blueberries::newChild(int turn, Coordinates Position)
{
	return new Blueberries(turn, myWorld, Position);
}
Event* Blueberries::collision(Organism* attacker)
{
	int attackerStrength = attacker->getStrength();

	Event* Returnevent = NULL;
	Returnevent = new Event(attacker->getPosition(), Call::kill, this->position);
	this->myWorld->eventManager(Returnevent);

	if (attackerStrength > strength)
	{
		return  new Event(attacker->getPosition(), Call::poison, attacker->getPosition());
	}
	return 0;
}