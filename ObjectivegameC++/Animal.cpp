#include "Animal.h"
#include <iostream>
#include <time.h>
Animal::Animal(int turnofbirth, World* newWorld, Coordinates position)
	:Organism(turn, newWorld, position) {};

Event* Animal::action()
{

	Coordinates nowekordy;
	int newx = position.x, newy = position.y;
	int randomx = (rand() % 3) - 1;
	int randomy = (rand() % 3) - 1;
	if (this->position.x + randomx >=0 && this->position.x + randomx <= this->myWorld->getWidth()-1)
	{
		newx = this->position.x + randomx;
	}
	if (this->position.y + randomy >= 0 && this->position.y + randomy <= this->myWorld->getHeight()-1)
	{
		newy = this->position.y + randomy;
	}
	nowekordy.newCoordinates(newx, newy);
	return new Event(this->position, Call::move, nowekordy);
}
bool Animal::reaction(Event* event)
{
	switch (event->getWhat())
	{
	case Call::move:
		//mozna sie bezpiecznie ruszyc
		if (event->getWho() == this->position)
		{
			this->position = event->getWhere();
			return true;
		}
		break;
	}
	return false;
}
Event* Animal::collision(Organism* attacker)
{
	if (this->getType() == attacker->getType())
	{
		//Moge ewentualnie zaimplementowac ze podczas tworzenia dziecka wykorzystywany jest jest tez ruch owcy z ktora mozna miec dziecko
		Coordinates childCords = this->position;
		int randomx =0;
		int randomy =0;
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
		} 
		while (  true);

		childCords.x += randomx;
		childCords.y += randomy;
		
		return new Event(this->position,Call::create, childCords);
	}
	return  new Event(attacker->getPosition(), Call::kill, this->position);
}