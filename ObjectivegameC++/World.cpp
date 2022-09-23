#include "World.h"

#include "Wolf.h"
#include "Fox.h"
#include "Human.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Antelope.h"

#include "Grass.h"
#include "Dandelion.h"
#include "Blueberries.h"
#include "Guarana.h"
#include "Borsch.h"

#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
using namespace std;

void World::iniMapa()
{
	this->turn = 0;
	this->numberofOrganism = 0;

	int const maxnumberofOrganizm = width * height / 3;
	int const maxSameOrg = maxnumberofOrganizm /4; // 2;
	int x =0, y =0;
	int numberofWolfes = 0;
	int numberofFox = 0;
	int numberofSheep = 0;
	int numberofTurtle = 0;
	int numberofAntelope = 0;
	int numberofGrass = 0;
	int numberofDandelion = 0;
	int numberofBlueberries = 0;
	int numberofGuarana = 0;
	int numberofBorsch = 1;
	
	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofFox)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Fox(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofFox++;
	}
	
	while (this->numberofOrganism < maxnumberofOrganizm &&  rand()% maxSameOrg>numberofWolfes)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Wolf(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofWolfes++;
	}

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofSheep)
	{
		do
		{
			y = rand() % (height);
			x = rand() % (width);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Sheep(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofSheep++;
	}

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofAntelope)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Antelope(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofAntelope++;
	}
	do
	{
		y = rand() % (width);
		x = rand() % (height);
	} while (map[x][y] != -1);

	census[numberofOrganism] = new Human(0, this, Coordinates(x, y));
	map[x][y] = numberofOrganism;
	numberofOrganism++;
	

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofTurtle)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Turtle(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofTurtle++;
	}

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofGrass)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Grass(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofGrass++;
	}
	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofDandelion)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Dandelion(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofDandelion++;
	}	
	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofBlueberries)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Blueberries(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofBlueberries++;
	}

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofGuarana)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Guarana(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofGuarana++;
	}

	while (this->numberofOrganism < maxnumberofOrganizm && rand() % maxSameOrg>numberofBorsch)
	{
		do
		{
			y = rand() % (width);
			x = rand() % (height);
		} while (map[x][y] != -1);

		census[numberofOrganism] = new Borsch(0, this, Coordinates(x, y));
		map[x][y] = numberofOrganism;
		numberofOrganism++;
		numberofBorsch++;
	}
}
World::World(int height,int width)
{
	this->turn = 0;
	this->numberofOrganism = 0;
	this->height = height;
	this->width = width;

	map = new int*[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new int[height];
	}
	census = new  Organism * [2 * width * height + 10]{ NULL };
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = -1;
		}
	}
}
void World::driveWorld()
{
	Sleep(500);
	system("cls");
	cout << " ____";
	for (int n = 0; n < this->width - 1; n++)
	{
		cout << "____";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		cout << "|";
		for (int j = 0; j < width; j++)
		{
			cout << " ";
			if (map[j][i] == -1)
			{
				cout << " ";
			}
			else
			{
				cout<<census[map[j][i]]->getKod();
			}
			cout << " ";
			if(j<width-1)
				cout << "|";
		}
		cout << "|"<<endl;
		if (i < height - 1)
		{
			cout << "|";
			for (int x = 0; x < width-1; x++)
			{
				cout << "----";
			}
			cout << "---";
			cout << "|" << endl;
		}

	}
	cout << " ____";
	for (int n = 0; n < this->width - 1; n++)
	{
		cout << "____";
	}
}
void World::fun()
{
	bool Notquit = true;
	char commend ='x';
	//driveWorld();
	cout << endl;
	cout << "press somethink to start" << endl;
	//_getch();
	while (Notquit == true)
	{

		cout << endl;
		driveWorld();
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "            TURN: " << turn << endl;
		cout << "----------------------------------" << endl;
		makeTurn();
		cout << endl;
		std::cout << "----------------------------------" << std::endl;
		cout << "press q to quit" << endl;
		cout << "press s to save" << endl;
		cout << "PRESS TO DO NEXT TURN" << endl;
		std::cout << "----------------------------------" << std::endl;
		commend = _getch();
		if (commend == 'q')
		{
			return;
		}
		else if (commend == 's')
		{
			save();
			return;
		}
	}

}
void World::makeTurn()
{
	this->turn++;
	Event* Returnevent = NULL;
	for (int i = 0; i < numberofOrganism; i++)
	{
		if (census[i] == nullptr)
			continue;

		if(census[i] != nullptr)
			Returnevent = census[i]->action();

		if (Returnevent != NULL)
			eventManager(Returnevent);
	}
	sortOrganism();
}
void World::eventManager(Event* event)
{
	int x = event->getWho().x;
	int y = event->getWho().y;

	int x2 = event->getWhere().x;
	int y2 = event->getWhere().y;

	Event* Returnevent = NULL;
	Organism* attacker = census[map[event->getWho().x][event->getWho().y]];
	Organism* defender = census[map[event->getWhere().x][event->getWhere().y]];

	Organism* parent = census[map[x][y]];
	Organism* child = parent->newChild(this->turn, event->getWhere());
	if (event == NULL) return;
	switch (event->getWhat())
	{
	default:
		break;
	case Call::move:

		if (map[x][y] !=-1 )
		{
			//Sprawdzam czy miejsce w które chce sie udac jest puste
			if (map[event->getWhere().x][event->getWhere().y] == -1 )
			{
				Organism* org = census[map[x][y]];
				if (org != NULL && org->reaction(event))
				{
					//cout << endl;
					//org->printType();
					//cout << "move from"<< event->getWho() <<"to "<< event->getWhere() << endl;

					int buf = map[event->getWho().x][event->getWho().y];
					map[event->getWho().x][event->getWho().y] = -1;
					map[event->getWhere().x][event->getWhere().y] = buf;
				}
			}
			else if (event->getWhere().x == event->getWho().x && event->getWhere().y == event->getWho().y)
			{
				break;
			}
			else
			{
				Returnevent = defender->collision(attacker);
				if (Returnevent != NULL)
				{
					eventManager(Returnevent);
				}
			}
		}
		break;
	case Call::killALL:
		if (map[x][y] != -1)
		{
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (x + i<this->width && x + i >=0 && y + j >=0 && y+j < this->height && map[x + i][y + j] != -1 && !(i ==0 &&j ==0))
					{
						census[map[x][y]]->printType();
						cout << " Kill around ";
						census[map[x + i][y + j]]->printType();
						cout << "<" << x + i << "," << y + j << ">" << endl;
						delete census[map[x + i][y + j]];
						census[map[x + i][y + j]] = nullptr;
						int buf = map[x + i][y + j];
						map[x + i][y + j] = -1;
					}
				}
			}
		}
		//driveWorld();
		break;
	case Call::killALLAnimals:
		if (map[x][y] != -1)
		{
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (x + i < this->width && x + i >= 0 && y + j >= 0 && y + j < this->height && map[x + i][y + j] != -1 && !(i == 0 && j == 0))
					{
						Type type = census[map[x + i][y + j]]->getType();
						if (type == Type::fox || type == Type::antylopa
							|| type == Type::human || type == Type::wolf
							|| type == Type::sheep || type == Type::turtle)
						{
							census[map[x][y]]->printType();
							cout << " Borsch poisoned ";
							census[map[x + i][y + j]]->printType();
							cout << "<" << x + i << "," << y + j << ">" << endl;
							delete census[map[x + i][y + j]];
							census[map[x + i][y + j]] = nullptr;
							int buf = map[x + i][y + j];
							map[x + i][y + j] = -1;
						}
					}
				}
			}
		}
		break;
	case Call::kill:
		if (attacker->getStrength() > defender->getStrength())
		{
			Coordinates temp = defender->getPosition();
			cout << endl;
			attacker->printType();
			cout << " Zabija ";
			defender->printType();
			cout << defender->getPosition() << endl;
			
			delete defender;
			census[map[event->getWhere().x][event->getWhere().y]] = nullptr;
			map[event->getWhere().x][event->getWhere().y] = -1;
			eventManager(new Event(attacker->getPosition(), Call::move, temp));
		}
		else
		{
			Coordinates temp = attacker->getPosition();
			cout << endl;
			defender->printType();
			cout << " Zabija ";
			attacker->printType();

			delete attacker;
			census[map[event->getWho().x][event->getWho().y]] = nullptr;
			map[event->getWho().x][event->getWho().y] = -1;

		}
		break;
	
	case Call::create:
		census[numberofOrganism] = child;

		map[x2][y2] = numberofOrganism;
		numberofOrganism++;
		cout << "Create ";
		parent->printType();
		cout << event->getWhere()<< endl;
		break;
	case Call::poison:
		cout << "Blueberries poision ";
		census[map[x][y]]->printType();
		cout << event->getWhere()<<endl;

		delete attacker;
		census[map[event->getWho().x][event->getWho().y]] = nullptr;
		map[event->getWho().x][event->getWho().y] = -1;
		break;
	}
	

	delete event;
}
void World::sortOrganism()
{
	//chyba naprawione
	for (int i = 0; i < numberofOrganism; i++)
	{
		for (int j = 1; j < numberofOrganism; j++)
		{
			if (census[j - 1] == nullptr || census[j] ==nullptr)
			{
				continue;
			}
			if (census[j - 1]->getInitiative() < census[j]->getInitiative())
			{
				//zamiana j-1 = j
				Organism* temp = census[j - 1];
				census[j - 1] = census[j];
				census[j] = temp;
				this->sortmap(j-1);
				//map[x][y] =9
			}
			if (census[j - 1]->getInitiative() == census[j]->getInitiative())
			{
				if (census[j - 1]->getTurn() > census[j]->getTurn())
				{
					Organism* temp = census[j - 1];
					census[j - 1] = census[j];
					census[j] = temp;
					this->sortmap(j - 1);
				}
			}
		}
	}
}
int World::getHeight()
{
	return height;
}
int World::getWidth()
{
	return width;
}
void World::sortmap(int j)
//j numer w censusie
//j-1 = j
{
	int a1 =-1, a2 =-1, b1 =-1, b2 = -1;
	for (int a = 0; a < this->width; a++)
	{
		for (int b = 0; b < height; b++)
		{
			if(map[a][b] == j)
			{
				a1 = a;
				b1 = b;
			}
			else if(map[a][b] == j+1)
			{
				a2 = a;
				b2 = b;
			}
		}
	}
	map[a1][b1] = map[a2][b2];
	map[a2][b2] = j ;
}
int World::getmapCords(int x,int y)
{
	return map[x][y];
}
bool World::checkcords(int x,int y)
{
	if (x <= width-1 && x >= 0 && y >= 0 && y <= height-1)
	{
		return true;
	}
	return false;
}
int World::getOrganismStrenghFrommap(int x, int y)
{
	return census[map[x][y]]->getStrength();
}
void World::save()
{
	int realnumberofOrganism =0;
	for (int index = 0; index < numberofOrganism; index++)
	{
		if (census[index] != nullptr)
		{
			realnumberofOrganism++;
		}

	}


	ofstream file(pathh, ios::out);
	file << width << " " << height << endl;
	file << turn << " " << realnumberofOrganism << endl;
	for (int index = 0; index < numberofOrganism; index++)
	{
		if (census[index] != nullptr)
		{
			census[index]->save(file);
		}
			
	}
	file.close();
}
void World::load(ifstream& file)
{
	file >> this->turn;
	file >> this->numberofOrganism;
	char c, symbol;
	for (int index = 0; index < numberofOrganism-1; index++)
	{
		//[ F 0 6 7  <3 , 3> ] 
		file >> c;
		file >> symbol;
		switch (symbol)
		{
		case 'A':
			census[index] = new Antelope(this->turn, this, Coordinates(0, 0));
			break;
		case 'C':
			census[index] = new Human(this->turn, this, Coordinates(0, 0));
			break;
		case 'W':
			census[index] = new Wolf(this->turn, this, Coordinates(0, 0));
			break;
		case 'S':
			census[index] = new Sheep(this->turn, this, Coordinates(0, 0));
			break;
		case 'F':
			census[index] = new Fox(this->turn, this, Coordinates(0, 0));
			break;
		case 'T':
			census[index] = new Turtle(this->turn, this, Coordinates(0, 0));
			break;
		case 'G':
			census[index] = new Grass(this->turn, this, Coordinates(0, 0));
			break;
		case '#':
			census[index] = new Dandelion(this->turn, this, Coordinates(0, 0));
			break;
		case '+':
			census[index] = new Guarana(this->turn, this, Coordinates(0, 0));
			break;
		case 'B':
			census[index] = new Blueberries(this->turn, this, Coordinates(0, 0));
			break;
		case 'X':
			census[index] = new Borsch(this->turn, this, Coordinates(0, 0));
			break;
		}
		census[index]->load(file);
		map[census[index]->getPosition().x][census[index]->getPosition().y] = index;
	}
	file.close();
}
World::~World()
{
	for (int i = 0; i < width; i++)
	{
		delete map[i];
	}
	for (int i = 0; i < numberofOrganism; i++)
	{
		if(census[i]!=nullptr)
			delete census[i];
	}
	delete census;
}