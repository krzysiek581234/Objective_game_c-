#include "Event.h"

Event::Event() {};
Event::Event(Coordinates who, Call what, Coordinates where)
{
	this->Who.x = who.x;
	this->Who.y = who.y;
	this->Where.x = where.x;
	this->Where.y = where.y;
	this->What = what;
}
Call Event::getWhat()
{
	return this->What;
}
Coordinates Event::getWho()
{
	return this->Who;
}
Coordinates Event::getWhere()
{
	return this->Where;
}