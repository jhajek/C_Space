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

void ship::setFuel(short f)
{
   fuel = f;
}

void ship::setFunds(short m)
{
	money = m;
}

short ship::getFuel(void)
{
	return fuel;
}

short ship::getFunds(void)
{
	return money;
}

void ship::setIron(short i)
{
   iron = i;
}

void ship::setSugar(short s)
{
	sugar = s;
}

short ship::getIron(void)
{
	return iron;
}

short ship::getSugar(void)
{
	return sugar;
}
void ship::setRice(short r)
{
	rice = r;
}

short ship::getRice(void)
{
	return rice;
}
void ship::setCARGO_MAX(short c)
{
	CARGO_MAX = c;
}

short ship::getCARGO_MAX(void)
{
	return CARGO_MAX;
}

ship::~ship()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}