#include<iostream>
using namespace std;

class planet
{
private:
	short xPos;
	short yPos;
	short zPos;
	char planetName[50];
public:
	planet(short x,short y,short z,char *); // constructor
	void setX(short x);
	void setY(short y);
	void setZ(short z);
	void setPlanetName(char[]);
	short getX();
	short getY();
	short getZ();
	char getPlanetName() const;
	~planet();
};

planet::planet(short x, short y, short z, char *name)
{
  xPos = x;
  yPos = y;
  zPos = z;
  strcpy(planetName,name);

}

void planet::setX(short x)
{
  xPos = x;
}
void planet::setY(short y)
{
  yPos = y;
}
void planet::setZ(short z)
{
  zPos = z;
}
void planet::setPlanetName(char *name)
{
  *planetName=*name;
}
short planet::getX()
{
	return xPos;
}
short planet::getY()
{
	return yPos;
}
short planet::getZ()
{
	return zPos;
}
char planet::getPlanetName() const 
{
	return *planetName;
}

planet::~planet()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}