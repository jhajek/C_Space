#include <iostream>
#include "ship.h"
#include "unit.h"
using namespace std;

/*ship::ship(char *name) : unit (xPos,yPos,zPos)
{ 
  strcpy(pilotName,name);

}
*/
void ship::setShipName(char *name)
{
  *shipName=*name;
}

void ship::setFuel(double f)
{
   fuel = f;
}

void ship::setFunds(int m)
{
	money = m;
}

double ship::getFuel(void)
{
	return fuel;
}

int ship::getFunds(void)
{
	return money;
}

void ship::setIron(int i)
{
   iron = i;
}

void ship::setSugar(int s)
{
	sugar = s;
}

int ship::getIron(void)
{
	return iron;
}

int ship::getSugar(void)
{
	return sugar;
}
void ship::setRice(int r)
{
	rice = r;
}

int ship::getRice(void)
{
	return rice;
}
void ship::setCARGO_MAX(int c)
{
	CARGO_MAX = c;
}

int ship::getCARGO_MAX(void)
{
	return CARGO_MAX;
}

ship::~ship()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}