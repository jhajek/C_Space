#include <iostream>
#include "planet.h"
#include "unit.h"
using namespace std;

/*planet::planet(char *name) : unit (xPos,yPos,zPos)
{ 
  strcpy(planetName,name);
}
/*
void planet::setX(short x)
{
  xPos = x;
}
void planet::setY(short y)
{
  yPos = y;
}
void planet::setZ(short z)
{
  zPos = z;
}
*/
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
short planet::getFuel(void)
{
	return fuel;
}

void planet::setFuel(short f)
{
   fuel = f;
}

short planet::getFuelPrice(void)
{
	return fuelPrice;
}

void planet::setFuelPrice(short fp)
{
	fuelPrice=fp;
}

void planet::setFunds(short m)
{
	money = m;
}

short planet::getFunds(void)
{
	return money;
}
void planet::setIron(short i)
{
   iron = i;
}

void planet::setSugar(short s)
{
	sugar = s;
}

short planet::getIron(void)
{
	return iron;
}

short planet::getSugar(void)
{
	return sugar;
}
void planet::setRice(short r)
{
	rice = r;
}

short planet::getRice(void)
{
	return rice;
}
void planet::setIronPrice(short ip)
{
	ironPrice = ip;
}

short planet::getIronPrice(void)
{
	return ironPrice;
}
void planet::setSugarPrice(short sp)
{
	sugarPrice = sp;
}

short planet::getSugarPrice(void)
{
	return sugarPrice;
}
void planet::setRicePrice(short rp)
{
	ricePrice = rp;
}

short planet::getRicePrice(void)
{
	return ricePrice;
}



planet::~planet()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}