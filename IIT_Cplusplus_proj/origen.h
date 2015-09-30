// origen.h
// Definition of origen planet
#ifndef ORIGEN_H
#define ORIGEN_H

#include<iostream>


class origen
{
protected:
   short xPos;
   short yPos;
   short zPos;
public:
   origen(short x, short y, short z) : xPos(x), yPos(y), zPos(z) {}
   void setX(short newX) {xPos = newX;}
   void setY(short newY) {yPos = newY;}
   void setZ(short newZ) {zPos = newZ;}
   short getX() const {return xPos;}
   short getY() const {return yPos;}
   short getZ() const {return zPos;}
	~origen();
};
#endif