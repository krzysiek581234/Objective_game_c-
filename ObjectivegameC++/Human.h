#pragma once
#include "Animal.h"
#include <Windows.h> //sleep
#include <conio.h> // kbhit getch
#define KEYRIGHT 77
#define KEYLEFT 75
#define KEYDOWN 80
#define KEYUP 72
#define KEYBOARD 224
class Human : public Animal
{
private:
	const int StartStrength = 15;
	const int StartInitiative = 4;
	const int durationSuperPower = 5;
	const int superPowerRechargeTime = 5 + durationSuperPower;
	int supermoc;
	int timeofSuperPower;
	int loadingSuperPower;
	bool issuperPowerLoad = false;
	//void getkey();
public:
	Human(int tura, World* newWorld, Coordinates Pos);
	Organism* newChild(int turn, Coordinates Pos) override;
	Event* action() override;
	void save(std::ofstream& file) override;
	void load(std::ifstream& file) override;
};
