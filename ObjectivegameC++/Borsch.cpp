#include "Borsch.h"

Borsch::Borsch(int tura, World* newWorld, Coordinates Pos) : Plant(tura, newWorld, Pos)
{
	this->kod = 'X';
	this->type = Type::Borsch;
	this->strength = 10;
}
Organism* Borsch::newChild(int turn, Coordinates Position)
{
	return new Borsch(turn, myWorld, Position);
}
Event* Borsch::collision(Organism* attacker)
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
Event* Borsch::action()
{
	
	Event* Returnevent = NULL;
	Returnevent = new Event(this->position, Call::killALLAnimals, this->position);
	this->myWorld->eventManager(Returnevent);
	for (int i = 0; i < seeds; i++)
	{
		if (rand() % 101 <= chanceofspreding)
		{
			Coordinates childCords = this->position;
			int randomx = 0;
			int randomy = 0;
			bool nospace = true;
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (this->myWorld->checkcords(childCords.x + i, childCords.y + j)
						&& this->myWorld->getmapCords(childCords.x + i, childCords.y + j) == -1)
					{
						nospace = false;
						break;
					}
				}
			}
			if (nospace == true)
				return NULL;
			do
			{
				randomx = (rand() % 3) - 1;
				randomy = (rand() % 3) - 1;
				if (this->myWorld->checkcords(childCords.x + randomx, childCords.y + randomy))
					if (this->myWorld->getmapCords(childCords.x + randomx, childCords.y + randomy) == -1)
						break;
			} while (true);
			childCords.x += randomx;
			childCords.y += randomy;

			return new Event(this->position, Call::create, childCords);
		}
	}
	
	return 0;
}