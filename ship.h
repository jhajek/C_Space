// UNIT.H
// Definition of class ship
#ifndef SHIP_H
#define SHIP_H

#include<iostream>
#include "unit.h"
using namespace std;

class ship : public unit
{
public:
	int x;
	int y;
	//int z;
	char shipName[50];
	double fuel;
	int money;
    int iron;
	int sugar;
	int rice;
    int CARGO_MAX;
public:
	//ship(int xPos, int yPos, int zPos, char* name, int f, int m) : unit(xPos,yPos,zPos) {x=xPos, y=yPos, z=zPos;}  // two dimensional
    ship(int xPos, int yPos, char* name, double f, int m, int i, int s, int r, int c) : unit(xPos,yPos) {x=xPos, y=yPos,fuel=f,money=m,sugar=s,rice=r,iron=i,CARGO_MAX=c; }

	void setShipName(char[]);
	void setFuel(double); 
	void setFunds(int); 
    void setIron(int);
	void setSugar(int);
	void setRice(int);
	void setCARGO_MAX(int);

	char* getShipName() const;
	double getFuel(void);
	int getFunds(void);
	int getIron(void);
	int getSugar(void);
	int getRice(void);
    int getCARGO_MAX(void);
	~ship();
};
#endif
