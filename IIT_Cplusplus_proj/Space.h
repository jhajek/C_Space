#include <iostream>
using namespace std;

class unit
{
private:
   short xPos;
   short yPos;
   short zPos;
public:
   unit(short x, short y, short z);
   void setX(short x);
   void setY(short y);
   void setZ(short z);
   short getX();
   short getY();
   short getZ();
   ~unit();
};
 
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


unit::~unit()
{
 //  cout << "unit has been destroyed... Good Job." << endl;
}