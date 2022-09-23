#include "Fox.h"

Fox::Fox(int tura, World* newWorld, Coordinates Pos) :Animal(tura, newWorld, Pos)
{
	this->kod = 'F';
	this->initiative = this->StartInitiative;
	this->strength = this->StartStrength;
	this->type = Type::fox;
}

Organism* Fox::newChild(int turn, Coordinates Position)
{
	return new Fox(turn, myWorld, Position);
}
Event* Fox::action()
{
	Coordinates newCords;
	int newx = position.x, newy = position.y;
	int randomx = -1;
	int	randomy = -1;
	int notmove = 0;

	do
	{
		randomx = (rand() % 3) - 1;
		randomy = (rand() % 3) - 1;
		notmove++;
		if (this->myWorld->checkcords(newx + randomx, newy + randomy) &&(randomx != 0 && randomy != 0))
			if(this->myWorld->getmapCords(newx + randomx, newy + randomy) == -1)
				break;
			else if (this->myWorld->getOrganismStrenghFrommap(newx + randomx, newy + randomy) <= strength)
				break;
		if (notmove == 10)
			return 0;
	} while (true);
	newCords.newCoordinates(newx + randomx, newy + randomy);
	return new Event(this->position, Call::move, newCords);
}
