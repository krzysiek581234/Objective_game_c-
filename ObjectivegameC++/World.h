#ifndef _WORLD
#define _WORLD
#define pathh "../Saves/save.txt"
#include "Organism.h"

#include "Event.h"
#include <iostream>
class Organism;
class World
{

private:
	int height;
	int width;
	int numberofOrganism;
	int turn;
	int** map;
	Organism** census;
	void sortmap(int j);
	void sortOrganism();
	void makeTurn();

	
public:
	void driveWorld();
	World(int height, int width);
	~World();
	void iniMapa();
	void fun();
	void eventManager(Event* eventZwrotny);
	int getHeight();
	int getWidth();
	int getmapCords(int x,int y);
	bool checkcords(int x, int y);
	int getOrganismStrenghFrommap(int x, int y);
	void save();
	void load(std::ifstream& file);
};

#endif
