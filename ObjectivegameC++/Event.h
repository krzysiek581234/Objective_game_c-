#pragma once
#include "Coordinates.h"

enum class Call
{
	move,
	kill,
	create,
	humanmove,
	poison,
	killALL,
	killALLAnimals
};

class Event
{
public:
	Event();
	Event(Coordinates Who, Call What, Coordinates Where);
	Call getWhat();
	Coordinates getWho();
	Coordinates getWhere();
protected:
	Coordinates Who;
	Coordinates Where;
	Call What;
};

