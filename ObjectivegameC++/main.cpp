#include <iostream>

#include "Menu.h"
#include "World.h"
#include "Organism.h"
#include "Coordinates.h"
#include "Event.h"
#include "EventList.h"

#include "Animal.h"

#include "Wolf.h"
#include "Human.h"

#define DEFEULT_HEIGHT 20
#define DEFEULT_WIDTH 20

using namespace std;
int main()
{
    srand(time(NULL));
    int height = DEFEULT_HEIGHT;
    int width = DEFEULT_WIDTH;
    Menu::initMenu();

    int result = Menu::getMenu(height, width);
    if (result == 1)
    {
        World funWorld = *new World(height, width);
        funWorld.iniMapa();
        funWorld.fun();
    }
    else if (result == 2)
    {
        std::ifstream plik(pathh, std::ios::in);
        if (!plik.fail())
        {
            plik >> width;
            plik >> height;
            World funWorld = *new World(height, width);
            funWorld.load(plik);
            funWorld.fun();
            funWorld.~World();
        }
    }
    return 0;
    
}
