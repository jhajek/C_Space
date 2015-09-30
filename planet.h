// planet.h
// Definition of class planet
#ifndef PLANET_H
#define PLANET_H

#include<iostream>
#include "unit.h"
#include "ship.h"


class planet : public unit
{
private:
	int x;
	int y;
//	int z;
	char planetName[50];
	int money;
	int fuel;
	int ironQuantity;
	int sugarQuantity;
	int riceQuantity;
	int ironDesiredQuantity;
	int sugarDesiredQuantity;
	int riceDesiredQuantity;
	int fuelPrice;
public:
//	planet(int xPos, int yPos, int zPos, char* name) : unit(xPos,yPos,zPos) {x=xPos, y=yPos, z=zPos;} -- going two dims
	planet(int xPos, int yPos, char* name, int m, int f, int iq, int sq, int rq, int idq, int sdq, int rdq, int fp) : unit(xPos,yPos) {x=xPos, y=yPos,/*strcpy(name,planetName),*/fuel=f,money=m,sugarQuantity=sq,riceQuantity=rq,ironQuantity=iq,ironDesiredQuantity=idq,sugarDesiredQuantity=sdq,riceDesiredQuantity=rdq,fuelPrice=fp;}

	void setFuel(int); 
	void setFunds(int); 
	void setPlanetName(char[]);
    void setIronQuantity(int);
	void setSugarQuantity(int);
	void setRiceQuantity(int);
	void setIronDesiredQuantity(int);
	void setSugarDesiredQuantity(int);
	void setRiceDesiredQuantity(int);
	void setFuelPrice(int);
   	void Shop(ship &);
	void buyCommodity(ship &, string);
	void sellCommodity(ship &, string);

	char* getPlanetName(void);
	int getFuel(void);
	int getFunds(void);
	int getIronQuantity(void);
	int getSugarQuantity(void);
	int getRiceQuantity(void);
	int getIronDesiredQuantity(void);
	int getSugarDesiredQuantity(void);
	int getRiceDesiredQuantity(void);
	int getFuelPrice(void);
	char* printPlanetName(void);

	~planet();
};
#endif