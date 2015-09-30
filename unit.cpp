#include <iostream>
#include "unit.h"
using namespace std;
/*
unit::unit(int x, int y, int z)
{
   xPos = x;
   yPos = y;
   zPos = z;
}

void unit::setX(int x)
{
   xPos = x;
}
void unit::setY(int y)
{
   yPos = y;
}
void unit::setZ(int z)
{
   zPos = z;
}
 
int unit::getX()
{
   return xPos;
}
int unit::getY()
{
   return yPos;
}
int unit::getZ()
{
   return zPos;
}

*/
unit::~unit()
{
   cout << "Space has been destroyed... Good Job." << endl;
}