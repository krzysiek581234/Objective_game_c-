#pragma once
#include <iostream>
class Coordinates
{
public:
	int x, y;
	Coordinates();
	Coordinates(int x, int y);
	void newCoordinates(Coordinates newCords);
	void newCoordinates(int x, int y);
	
	bool friend operator ==(const Coordinates& left, const Coordinates& right)
	{
		if (left.x == right.x && left.y == right.y)
			return true;
		else
			return false;
	}
	friend std::ostream& operator<<(std::ostream& out, const Coordinates& p)
	{
		out << " <" << p.x << " , " << p.y << "> ";
		return out;
	}
};