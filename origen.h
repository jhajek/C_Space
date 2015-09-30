// origen.h
// Definition of origen planet
#ifndef ORIGEN_H
#define ORIGEN_H

#include<iostream>


class origen
{
protected:
   int xPos;
   int yPos;
   int zPos;
public:
   origen(int x, int y, int z) : xPos(x), yPos(y), zPos(z) {}
   void setX(int newX) {xPos = newX;}
   void setY(int newY) {yPos = newY;}
   void setZ(int newZ) {zPos = newZ;}
   int getX() const {return xPos;}
   int getY() const {return yPos;}
   int getZ() const {return zPos;}
	~origen();
};
#endif