#include <iostream>
#include "planet.h"
#include "unit.h"
using namespace std;

/*planet::planet(char *name) : unit (xPos,yPos,zPos)
{ 
  strcpy(planetName,name);
}
/*
void planet::setX(int x)
{
  xPos = x;
}
void planet::setY(int y)
{
  yPos = y;
}
void planet::setZ(int z)
{
  zPos = z;
}
*/

void planet::setPlanetName(char *name)
{
  //*planetName=*name;
	strcpy(name,planetName);
}
char* planet::getPlanetName(void)
{
  return planetName;
}

char* planet::printPlanetName(void)
{
   cout << planetName; 
   return planetName;
}

int planet::getFuel(void)
{
	return fuel;
}

void planet::setFuel(int f)
{
   fuel = f;
}

int planet::getFuelPrice(void)
{
	return fuelPrice;
}

void planet::setFuelPrice(int fp)
{
	fuelPrice=fp;
}

void planet::setFunds(int m)
{
	money = m;
}

int planet::getFunds(void)
{
	return money;
}
void planet::setIronQuantity(int iq)
{
   ironQuantity = iq;
}

void planet::setSugarQuantity(int sq)
{
	sugarQuantity = sq;
}

int planet::getIronQuantity(void)
{
	return ironQuantity;
}

int planet::getSugarQuantity(void)
{
	return sugarQuantity;
}
void planet::setRiceQuantity(int rq)
{
	riceQuantity = rq;
}

int planet::getRiceQuantity(void)
{
	return riceQuantity;
}
void planet::setIronDesiredQuantity(int idq)
{
	ironDesiredQuantity = idq;
}

int planet::getIronDesiredQuantity(void)
{
	return ironDesiredQuantity;
}
void planet::setSugarDesiredQuantity(int sdq)
{
	sugarDesiredQuantity = sdq;
}

int planet::getSugarDesiredQuantity(void)
{
	return sugarDesiredQuantity;
}
void planet::setRiceDesiredQuantity(int rdq)
{
	riceDesiredQuantity = rdq;
}

int planet::getRiceDesiredQuantity(void)
{
	return riceDesiredQuantity;
}
// added by Soren Haurburg
//void Planet::Shop(int &money, int &fuel, Commodity &shipIron, Commodity &shipSugar, Commodity &shipRice, int CARGO_MAX)
void planet::Shop(ship &s)
{
//	HANDLE hStdout;
 //   hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
 //   SetConsoleActiveScreenBuffer(hStdout);
	 
	char pressedKey = '0';
	while(pressedKey != 'E' && pressedKey != 'e')
	{
	  system("cls");
//	  SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED);
	  cout << "\n\t\t\tWelcome to " << *planetName << endl;
//	  SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	  cout << "\tYou have the follwing..." << endl;
	  cout << "\t\tIron: " << s.getIron() << "Sugar: " << s.getSugar() << "Rice: " << s.getRice() << endl;
	  cout << "\t\tMoney: " << s.getFunds() << "Fuel: " << s.getFuel() << "Cargo Space left: " << s.getCARGO_MAX()-(s.getIron()+s.getRice()+s.getSugar()) << endl; 
	  cout << "\n\tHere are your available actions on planet " << /*planetName*/ "Jupiter" << ":" << endl;
	  
	  
	  
	  if (ironDesiredQuantity>ironQuantity)
	  {
            cout << "\n\t\t\t1. "<< *planetName << "will Buy Iron for: " << ((ironDesiredQuantity/ironQuantity) * ironQuantity) << endl;
	  }
	  else 
	  {
           cout << "\t\t\t5. " << *planetName << "will sell Iron for: " << ((ironQuantity/ironDesiredQuantity) * ironQuantity) << endl;
	  }
	  /*cout << "\n\t\t\t1. Buy Iron for: " << Iron.getBuyValue() << endl;
	  cout << "\t\t\t2. Buy Sugar for: " << Sugar.getBuyValue() << endl;
	  cout << "\t\t\t3. Buy Rice for: " << Rice.getBuyValue() << endl;
	  cout << "\t\t\t4. Buy Fuel for: " << fuelPrice << endl;
	  cout << "\t\t\t5. Sell Iron for: " << Iron.getSellValue() << endl;
	  cout << "\t\t\t6. Sell Sugar for: " << Sugar.getSellValue() << endl;
	  cout << "\t\t\t7. Sell Rice for: " << Rice.getSellValue() << endl;
	  cout << "\t\t\tU. Buy Upgrades" << endl;
	  */
	  cout << "\t\t\tE. Exit " << "Planet Name Here";
      cin >> pressedKey;
	 
	  switch(pressedKey)
	  {
	   case '1': 	  
	        buyCommodity(s, "Iron");   
	   break;
	   case '2':
//			buyCommodity(s, Sugar);
	   break;
	   case '3':
	//		buyCommodity(s, Rice);
	   break;
       case '4':
	//		buyFuel(s);
	   break;
	   case '5':
			sellCommodity(s, "Iron");
	   break;
	   case '6':
	//	    sellCommodity(s, Sugar);
	   break;
	   case '7':
	//	    sellCommodity(s, Rice);
	   break;
	   case 'U':
	//		upgradeShip(s);
	   break;
	   case 'u':
	//		upgradeShip(s);
	   break;
	   case 'E':
		   //leaving planet
	   break;
	   case 'e':
		   //leaving planet
	   break;
	   default:
			cout << "Please pick one of the available options. " << endl;
	   break;
	  }// end of switch
	}
  } 
/************************************************************************
 *buyCommodity function                                                 *
 *used to calculate purchase of any commodity available at a planet     *
 * added by Soren H.  mangled by Jeremy 05.25.08                                                                     *
 ************************************************************************/
void planet::buyCommodity(ship &s, string c)
{

}

void planet::sellCommodity(ship &s, string c)
{

}
planet::~planet()
{
 //  cout << "Space has been destroyed... Good Job." << endl;
}