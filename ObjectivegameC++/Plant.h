#pragma once
#include "Organism.h"
class World;
class Plant : public Organism
{
protected:
	const int DEFAULTSTARTINITIATIVE = 0;
	const int DEFAULTSTARTSTRENGH = 0;
	const int CHANCEOFSPREDING = 10;
	const int DEFULTSEEDS = 1;
	Plant(int turnofbirth, World* newWorld, Coordinates position);
	double chanceofspreding;
	int seeds;
public:
	Event* action() override;
	Event* collision(Organism* attacker) override;
	bool reaction(Event* event) override;
	virtual Organism* newChild(int tura, Coordinates Pos) override = 0;

};
