#pragma once
#include "Organism.h"
class World;
class Animal : public Organism
{
protected:
		Animal(int turnofbirth, World* newWorld, Coordinates position);
public:
	Event* action() override; //override
	bool reaction(Event* event) override;
	Event* collision(Organism* attacker) override;
	//void driveWorld() override;
	virtual Organism* newChild(int tura, Coordinates Pos) override = 0;

};
