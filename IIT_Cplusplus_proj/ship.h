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
	short x;
	short y;
	//short z;
	char shipName[50];
	short fuel;
	short money;
    short iron;
	short sugar;
	short rice;
    short CARGO_MAX;
public:
	//ship(short xPos, short yPos, short zPos, char* name, short f, short m) : unit(xPos,yPos,zPos) {x=xPos, y=yPos, z=zPos;}  // two dimensional
    ship(short xPos, short yPos, char* name, short f, short m, short i, short s, short r, short c) : unit(xPos,yPos) {x=xPos, y=yPos,fuel=f,money=m,sugar=s,rice=r,iron=i,CARGO_MAX=c; }

	void setShipName(char[]);
	void setFuel(short); 
	void setFunds(short); 
    void setIron(short);
	void setSugar(short);
	void setRice(short);
	void setCARGO_MAX(short);

	char* getShipName() const;
	short getFuel(void);
	short getFunds(void);
	short getIron(void);
	short getSugar(void);
	short getRice(void);
    short getCARGO_MAX(void);
	~ship();
};
#endif
