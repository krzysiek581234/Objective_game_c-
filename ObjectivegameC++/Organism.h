#pragma once
#include "Coordinates.h"
#include "Event.h"
#include "World.h"

#include <iostream>
#include <fstream>
#include <string>
class World;


enum class Type
{
	human,
	sheep,
	fox,
	wolf,
	turtle,
	antylopa,
	grass,
	dandelion,
	guarana,
	blueberries,
	Borsch
};

class Organism
{
protected:
	char kod;
	int strength;
	int initiative;
	int turn;
	Coordinates position;
	World *myWorld;
	Type type;
	Organism(int turnofbirth, World *newWorld, Coordinates position);
public:
	virtual Event* action() = 0;
	virtual Event* collision(Organism* attacker) = 0;
	virtual bool reaction(Event* event) = 0;
	virtual Organism* newChild(int tura, Coordinates Pos) = 0;
	
	virtual void save(std::ofstream& plik);
	virtual void load(std::ifstream& plik);


	void addStrength(int strength);
	char getKod();
	int getStrength();
	int getInitiative();
	int getAge();
	int getTurn();
	Type getType();
	void printType();
	Coordinates getPosition();

	//void getPosition();
	
	friend std::ostream& operator<<(std::ostream& out, Type typ);
};


