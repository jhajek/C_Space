// UNIT.H
// Definition of class unit
#ifndef UNIT_H
#define UNIT_H

#include <iostream>


class unit
{
protected:
   int xPos;
   int yPos;
   //int zPos;
public:
   //unit(int x, int y, int z) : xPos(x), yPos(y), zPos(z) {} -- going to 2 dimensional grid 
   unit(int x, int y) : xPos(x), yPos(y) {}
   void setX(int newX) {xPos = newX;}
   void setY(int newY) {yPos = newY;}
   //void setZ(int newZ) {zPos = newZ;}
   int getX() const {return xPos;}
   int getY() const {return yPos;}
   //int getZ() const {return zPos;}
   ~unit();
};
 
#endif