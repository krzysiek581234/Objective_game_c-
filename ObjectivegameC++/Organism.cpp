#include "Organism.h"
#include "World.h"


class Coordinates;
Organism::Organism(int turnofbirth, World* newWorld, Coordinates position)
{
	this->turn = turnofbirth;
	this->myWorld = newWorld;
	this->position = position;
	this->strength = 0;
	this->initiative = 0;
}
void Organism::addStrength(int str)
{
	Organism::strength += str;
}
char Organism::getKod()
{
	return kod;
}
int Organism::getStrength()
{
	return strength;
}
int Organism::getInitiative()
{
	return initiative;
}
int Organism::getAge()
{
	//TO DO
	return turn;
}

Coordinates Organism::getPosition()
//void Organism::getPosition()
{
	//std::cout << position.x<< std::endl;
	//std::cout << position.y<< std::endl;
	return position;
}



std::ostream& operator<<(std::ostream& out, Type typ)
{
	switch (typ)
	{
	case Type::human:
		out << "human";
		break;
	case Type::sheep:
		out << "sheep";
		break;
	case Type::wolf:
		out << "wolf";
		break;
	case Type::fox:
		out << "fox";
		break;
	case Type::antylopa:
		out << "Antylopa";
		break;
	case Type::turtle:
		out << "Turtle";
		break;
	case Type::grass:
		out << "Grass";
		break;
	case Type::dandelion:
		out << "Dandelion";
		break;
	case Type::guarana:
		out << "Guarana";
		break;
	case Type::blueberries:
		out << "Blueberries";
		break;
	case Type::Borsch:
		out << "Borsch";
	default:
		out << "no found";
		break;
	}
	return out;
}
Type Organism::getType()
{
	return this->type;
}
void Organism::printType()
{
	std::cout << this->type<< ": ";
}
int Organism::getTurn()
{
	return turn;
}
void Organism::save(std::ofstream& plik)
{
	plik << "[ " << kod << " " << turn << " " << strength << " " << initiative;
	plik << " " << this->position << "] " << std::endl;
}
void Organism::load(std::ifstream& plik)
{
	char c;
	//[ C 0 15 4  <2 , 1> ] 
	plik >> turn;
	plik >> strength;
	plik >> initiative;
	plik >> c;
	plik >> position.x;
	plik >> c;
	plik >> position.y;
	plik >> c;
	plik >> c;
}


