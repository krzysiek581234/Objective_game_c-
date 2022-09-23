#include "Turtle.h"

Turtle::Turtle(int tura, World* newWorld, Coordinates Pos) :Animal(tura, newWorld, Pos)
{
	this->kod = 'T';
	this->initiative = this->StartInitiative;
	this->strength = this->StartStrength;
	this->type = Type::wolf;
}

Organism* Turtle::newChild(int turn, Coordinates Position)
{
	return new Turtle(turn, myWorld, Position);
}
Event* Turtle::action()
{
	Coordinates newCords;
	int newx = position.x, newy = position.y;
	int randomx = 0;
	int	randomy = 0;
	int error = 0;
	if (rand() % 4 == 0)
	{
		do
		{
			randomx = (rand() % 3) - 1;
			randomy = (rand() % 3) - 1;
			if (this->myWorld->checkcords(newx + randomx, newy + randomy) && (randomx != 0 && randomy != 0))
				if (this->myWorld->getmapCords(newx + randomx, newy + randomy) == -1)
					break;
			error++;
			if (error == 10)
				return 0;
		} while (true);
	}
	newCords.newCoordinates(newx + randomx, newy + randomy);
	return new Event(this->position, Call::move, newCords);
}
Event* Turtle::collision(Organism* attacker)
{
	if (getType() == attacker->getType())
	{
		//Moge ewentualnie zaimplementowac ze podczas tworzenia dziecka wykorzystywany jest jest tez ruch owcy z ktora mozna miec dziecko
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
	if (attacker->getStrength() > 5)
		return  new Event(attacker->getPosition(), Call::kill, this->position);
	else
		std::cout << "Turtle defended himself";;
	return NULL;
}