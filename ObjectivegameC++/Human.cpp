#include "Human.h"
#include <iostream>
Human::Human(int tura, World* newWorld, Coordinates Pos) :Animal(tura, newWorld, Pos)
{
	this->kod = 'C';
	this->initiative = this->StartInitiative;
	this->strength = this->StartStrength;
	this->type = Type::human;
	this->supermoc = 0;
	this->timeofSuperPower = 0;
	this->loadingSuperPower = 0;
}

Event* Human::action()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Enter the Human move! "<<std::endl;
	if (supermoc == 1)
	{
		this->timeofSuperPower--;
		std::cout <<"Lest time with super Power" << timeofSuperPower << std::endl;
		if (timeofSuperPower == 0)
		{
			this->supermoc = 0;
			
		}
	}
	if (loadingSuperPower != 0)
	{
		this->loadingSuperPower--;
		std::cout << "Super Power ready in"<< this->loadingSuperPower <<std::endl;
	}
	if (supermoc == 0 && loadingSuperPower==0)
	{
		std::cout << "Enter S to use Superpower"<<std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	if (supermoc == 1)
	{
		//supermoc 5 s188674 kill all :)
		Event* Returnevent = NULL;
		Returnevent = new Event(this->position, Call::killALL, this->position);
		this->myWorld->eventManager(Returnevent);
		issuperPowerLoad = true;
	}
	while (true)
	{


		if (_kbhit())
		{
			unsigned char key = _getch();
			if (key == KEYBOARD)
			{
			
				Coordinates nowekordy = position;
				switch (_getch())
				{

				case KEYUP: //UP
					if (this->position.y-1 >= 0)
					{
						nowekordy.newCoordinates(position.x, position.y-1);
					}
					break;
				case KEYDOWN: //DOWN
					if (this->position.y < this->myWorld->getHeight() - 1)
					{
						nowekordy.newCoordinates(position.x, position.y+1);
					}
					break;
				case  KEYLEFT: //LEFT
					if (this->position.x > 0)
					{
						nowekordy.newCoordinates(position.x-1, position.y);
					}
					break;
				case KEYRIGHT: //RIGHT
					if (this->position.x < this->myWorld->getWidth() - 1)
					{
						nowekordy.newCoordinates(position.x+1, position.y);
					}
					break;
				}
				if (supermoc == 1)
				{
					//supermoc 5 s188674 kill all :)
					Event* Returnevent = NULL;
					Returnevent = new Event(this->position, Call::killALL, this->position);
					this->myWorld->eventManager(Returnevent);
				}
				return new Event(this->position, Call::move, nowekordy);
			}
			else if (key == 's')
			{
				if (loadingSuperPower == 0)
				{
					//supermoc aktywowana!
					std::cout << "Activated Super ability!" << std::endl;
					this->timeofSuperPower = durationSuperPower;
					this->supermoc = 1;
					this->loadingSuperPower = superPowerRechargeTime;
					return new Event(this->position, Call::killALL, this->position);
				}
			}

		}
		//Sleep(100);
	}
}
Organism* Human::newChild(int turn, Coordinates Pos)
{
	return NULL; //czlowiek sie nie rozmnarza
}
void Human::save(std::ofstream& file)
{
	file << "[ " << kod << " " << turn << " " << strength << " " << initiative;
	file << " " << supermoc << " " << timeofSuperPower << " " << loadingSuperPower << " " << issuperPowerLoad;
	file << " " << this->position << "] " << std::endl;
}
void Human::load(std::ifstream& file)
{
	char c;
	file >> turn;
	file >> strength;
	file >> initiative;
	file >> supermoc;
	file >> timeofSuperPower;
	file >> loadingSuperPower;
	file >> issuperPowerLoad;
	file >> c;
	file >> position.x;
	file >> c;
	file >> position.y;
	file >> c;
	file >> c;
}