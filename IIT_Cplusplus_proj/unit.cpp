#include <iostream>
#include "unit.h"
using namespace std;
/*
unit::unit(short x, short y, short z)
{
   xPos = x;
   yPos = y;
   zPos = z;
}

void unit::setX(short x)
{
   xPos = x;
}
void unit::setY(short y)
{
   yPos = y;
}
void unit::setZ(short z)
{
   zPos = z;
}
 
short unit::getX()
{
   return xPos;
}
short unit::getY()
{
   return yPos;
}
short unit::getZ()
{
   return zPos;
}

*/
unit::~unit()
{
   cout << "Space has been destroyed... Good Job." << endl;
}