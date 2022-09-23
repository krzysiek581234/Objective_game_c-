#include "Coordinates.h"
Coordinates::Coordinates() {};
Coordinates::Coordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Coordinates::newCoordinates(Coordinates newCords)
{
	this->x = newCords.x;
	this->y = newCords.y;
}
void Coordinates::newCoordinates(int x,int y)
{
	this->x = x;
	this->y = y;
}