#include "Plant.h"
#include "World.h"

Plant::Plant(int turnofbirth, World* newWorld, Coordinates position): Organism(turn, newWorld, position)
{
	this->initiative = this->DEFAULTSTARTSTRENGH;
	this->strength = this->DEFAULTSTARTINITIATIVE;
	this->chanceofspreding = this->CHANCEOFSPREDING;
	this->seeds = this->DEFULTSEEDS;
};

Event* Plant::action()
{
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
Event* Plant::collision(Organism* attacker)
{
	return  new Event(attacker->getPosition(), Call::kill, this->position);
}
bool Plant::reaction(Event* event)
{
	switch (event->getWhat())
	{
	case Call::move:
		return false; 
		break;
	case Call::poison:
		return false; 
		break;
	}
	return false;
};