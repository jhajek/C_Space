#include <iostream>
#include "planetoid.h"
#include "unit.h"
using namespace std;

/*planet::planet(char *name) : unit (xPos,yPos,zPos)
{ 
  strcpy(planetName,name);
}
/*
void planet::setPlanetName(char *name)
{
  //*planetName=*name;
	strcpy(name,planetName);
}
char* planet::getPlanetName(void)
{
  return planetName;
}
*/
double planetoid::getGravityFactor(void)
{
	return gravityFactor;
}

void planetoid::setGravityFactor(double gf)
{
   gravityFactor = gf;
}


planetoid::~planetoid()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}