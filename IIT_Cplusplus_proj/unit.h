// UNIT.H
// Definition of class unit
#ifndef UNIT_H
#define UNIT_H

#include <iostream>


class unit
{
protected:
   short xPos;
   short yPos;
   //short zPos;
public:
   //unit(short x, short y, short z) : xPos(x), yPos(y), zPos(z) {} -- going to 2 dimensional grid 
   unit(short x, short y) : xPos(x), yPos(y) {}
   void setX(short newX) {xPos = newX;}
   void setY(short newY) {yPos = newY;}
   //void setZ(short newZ) {zPos = newZ;}
   short getX() const {return xPos;}
   short getY() const {return yPos;}
   //short getZ() const {return zPos;}
   ~unit();
};
 
#endif