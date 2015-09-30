// planetoid.h
// Definition of class planetoid
#ifndef PLANETOID_H
#define PLANETOID_H

#include<iostream>
#include "unit.h"


class planetoid : public unit
{
private:
	int x;
	int y;
	double gravityFactor;
	char planetoidName[50];

public:
	planetoid(int xPos, int yPos, double gf, char* name): unit(xPos,yPos) {x=xPos, y=yPos,/*strcpy(name,planetName),*/gravityFactor=gf;}

	void setGravityFactor(double); 
	void setPlanetoidName(char[]);

	char* getPlanetoidName(void);
	double getGravityFactor(void);

	~planetoid();
};
#endif