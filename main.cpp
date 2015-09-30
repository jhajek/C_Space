#include<iostream>
#include "unit.h"
#include "planet.h"
#include "ship.h"
#include "origen.h"
#include "planetoid.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <windows.h>
#include <string>
#include <cctype>
#include <iostream> // for debugging right now
#include <fstream>  // ditto
#include <cmath> // for sqrt
//#include <stdio> // for date time


using namespace std; 

const int POSITIVE_XLIMIT=77;
const int NEGATIVE_XLIMIT=1;
const int POSITIVE_YLIMIT=19;
const int NEGATIVE_YLIMIT=1;
const int PLANET_NAME_SIZE=9;
const int UNIVERSE_ARRAY_SIZE=9;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
ifstream infile;
ofstream outfile;
time_t now = time(0);
// Convert now to tm struct for local timezone
tm* localtm = localtime(&now);


int* generateXPosition();
int* generateYPosition();
void travel(int,ship &);
int* generateCosts();
//void generatePlanets();
void drawMap(int,int, int, int, int, int,int,int,int,int,int,int, int, int,int,int,int,int,int,int,int,int,int,int);
int drawHUD(int, int, ship &);
//void drawHUD(int, int, ship &);
void checkIfAtPlanet(ship &,planet &,planet &, planet &,planet &,planet &, planet &,planet &,planet &, planet &);
void moveMoon(planet &);
//void buyIron(ship &,planet &);
//void buyRice(ship &,planet &);
//void buySugar(ship &,planet &);
void buyFuel(ship &,planet &);
//void sellIron(ship &,planet &);
int checkIfAtPlanetMenu(ship &, planet &);
int checkIfAtMoonMenu(ship &,planet &,planet &, planet &,planet &,planet &, planet &,planet &,planet &, planet &);
void randomEvent();
void parseMovement(string, string, ship &);
//int getXCoord(int);
//int getYCoord(int);
//void boundsCheck(Space &);
//http://www.learn-programming.za.net/programming_cpp_learn10.html
//http://www.fredosaurus.com/notes-cpp/misc/random.html
//http://www.codersource.net/c++_tutorial_functions.html
//http://www.velocityreviews.com/forums/t281617-returning-an-array-in-c-.html
//http://www.cs.uregina.ca/Links/class-info/170/inherit.html#2 <-- inheritance
//http://www.codersource.net/c++_vector_stl.html <-- vecotrs
//http://www.daniweb.com/forums/thread1769.html <-- random numbers
//http://www.go4expert.com/forums/showthread.php?t=2965 <-- change console color
int main()
{
	
   int *arrX=0;
   int *arrY=0;
   int *costArray=0;
   int input=0;
   int moonCounter=0;
   int number_of_planets=0;
   int movePosition=0;
//   int moonCounter=0;
   arrX = generateXPosition();
   arrY = generateYPosition();
   costArray = generateCosts();
//***********************************************************************************
// Create planet objects 
// structure is as follows:
// xPos,yPos,planetName,fuel,money,sugarQuantity,riceQuantity,ironQuantity,ironDesiredQuantity,sugarDesiredQuantity,riceDesiredQuantity,fuelPrice
// int xPos, int yPos, char* name, int m, int f, int iq, int sq, int rq, int idq, int sdq, int rdq, int fp
//**********************************************************************************
   planet jupiter(36,(*(arrY+1)),"Juptier",2000,6000,100,100,100,100,200,10,(*(costArray+24)));
   planet earth (12,(*(arrY)),"Earth",25000,10000,1000,1000,1000,1200,50,100,(*(costArray+24)));
   planet mars (3,(*(arrY+2)),"Mars",7000,0,0,100,100,0,500,0,(*(costArray+24)));
   planet ganymede (jupiter.getX()+0,jupiter.getY()+2,"Ganymede",5000,4000,0,500,0,0,500,0,(*(costArray+24)));
   planet moon(earth.getX()+0,earth.getY()+2,"Moon",0,0,0,0,0,0,0,0,0);
   planet saturn (24,(*(arrY+3)),"Saturn",(*(costArray+15)*10),6000,100,100,100,150,80,1,(*(costArray+24)));
   planet neptune (48,(*(arrY+4)),"Neptune",2000,6000,100,500,100,150,100,100,(*(costArray+24)));
   planet pluto (60,(*(arrY+5)),"Pluto",2000,1000,100,0,100,1000,0,500,(*(costArray+24)));
   planet ceres (72,(*(arrY+6)),"Ceres",1000,5000,1000,0,0,100,0,0,(*(costArray+24)));
   planetoid sun (75,(*(arrY+7)),2.5,"Sun");
   planetoid beltegeuse (18,(*(arrY+8)),10,"Beltegeuse");


   ship s(moon.getX(),moon.getY(),"Enterprise",500.0,10000,0,0,200,5000);

  
   while (input !=8) 
   {
   input=0;
   
    checkIfAtPlanet(s,jupiter,earth,mars,ganymede,moon,saturn,neptune,pluto,ceres);

  if (isalpha(input))
   {
	   input = -999;
   }
  
   //randomEvent();
   //marketFlux();	   
   // gotoX = getXCoord();
   // gotoY = getYCoord();
   drawMap(s.getX(),s.getY(),jupiter.getX(),jupiter.getY(),earth.getX(),earth.getY(),mars.getX(),mars.getY(),ganymede.getX(),ganymede.getY(),moon.getX(),moon.getY(),saturn.getX(),saturn.getY(),neptune.getX(),neptune.getY(),pluto.getX(),pluto.getY(),ceres.getX(),ceres.getY(),sun.getX(),sun.getY(),beltegeuse.getX(),beltegeuse.getY());
   //drawHUD(moon.getX(),moon.getY(),s);
   input = drawHUD(moon.getX(),moon.getY(),s);
   travel(input,s);
   moveMoon(moon);
   system("cls");
   } // end of main while loop

   return 0;
} 
//***********************************************************************************
// void checkIfAtPlanet()  
// This fucntion checks to see if you have arrived at a planet, then it'd put you
// in the store.
// 
//**********************************************************************************
void checkIfAtPlanet(ship &s,planet &jupiter,planet &earth,planet &mars,planet &ganymede,planet &moon,planet &saturn,planet &neptune,planet &pluto,planet &ceres)
{
   short input = 0;
//**********************************************************************************
// 1. Jupiter
//**********************************************************************************
	if (s.getX()==jupiter.getX() && s.getY()==jupiter.getY())
    {
	   jupiter.Shop(s);
	
	  
	}
      // end of jupiter if
//**********************************************************************************
// 2. Earth
//**********************************************************************************
      if (s.getX()==earth.getX() && s.getY()==earth.getY())
   {
	   earth.Shop(s);
	
	 
	}
// end of earth if	   
//**********************************************************************************
// 3. Mars
//**********************************************************************************
      if (s.getX()==mars.getX() && s.getY()==mars.getY())
   {
	   mars.Shop(s);
	
	  
	}
// end of mars if
//**********************************************************************************
// 4. Ganymede
//**********************************************************************************
   if (s.getX()==ganymede.getX() && s.getY()==ganymede.getY())
   {
	   
	  ganymede.Shop(s);
	  
 
    }
//**********************************************************************************
// 5. Saturn
//**********************************************************************************
   if (s.getX()==saturn.getX() && s.getY()==saturn.getY())
   {

       saturn.Shop(s);
	 
 
    }
//**********************************************************************************
// 6. Pluto
//**********************************************************************************
	     if (s.getX()==pluto.getX() && s.getY()==pluto.getY())
   {
	
	   pluto.Shop(s);
	 
 
    }
//**********************************************************************************
// 7. Ceres
//**********************************************************************************
		 
		 if (s.getX()==ceres.getX() && s.getY()==ceres.getY())
   {
	 ceres.Shop(s);
	
 
    }
//**********************************************************************************
// 8. Neptune
//**********************************************************************************
		 
		 if (s.getX()==neptune.getX() && s.getY()==neptune.getY())
   {
        neptune.Shop(s);	  
	 
 
    }
//**********************************************************************************
// 9. Moon -- different from planet
//**********************************************************************************
  if (s.getX()==moon.getX() && s.getY()==moon.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtMoonMenu(s,jupiter,earth,mars,ganymede,moon,saturn,neptune,pluto,ceres);	  
         
	   cout << "1. Check Mail Box: -- Not Functional... " << endl;
	   cout << "2. Repair Ship: -- Not Functional... " << endl;
	   cout << "3. Upgrade Ship: -- Not Functional... " << endl;
	   cout << "4. Pick Up Passengers: -- Not Functional... " << endl;
	   cout << "5. Talk to people listen to space news... -- not functional... " << endl;


       switch(input)
	   {
	   case 1: 
		   system("cls");
           //checkMailBox();   
		   cout << "N/A" << endl;
		   break;
	   case 2:
     	   system("cls");
           //repairShip();
		   cout << "N/A" << endl;
		   break;
	   case 3:
     	   system("cls");
		   //upgradeShip();
           cout << "N/A" << endl;
		   break;
	   case 4:
     	   system("cls");
		   //pickUpPassengers();
           cout << "N/A" << endl;
		   break;
	   case 5:
     	   system("cls");
		   //talkToPeople();
           cout << "N/A" << endl;
		   break;
		case 6:
     	   system("cls");
           cout << "Take Care out there in space..." << endl;
		   break;

	   default:
		     cout << "You can only choose option 1-5 are not programmed, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5);
	   s.setX(s.getX()+1);
	   s.setY(s.getY()+1);
 
    }

  s.setX(s.getX()+1);
} // end of method
//********************************************************************************************
// int* generateXPosition() 
// This method is used to generate a random number between 1-80 to generate an X coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of ints.
//********************************************************************************************
int* generateXPosition()
{
    //int i=0;
	int r;
	int *arrX = new int[30];

    
//    r = (((( rand() % 10) * 10));
    srand(time(NULL));
	int lowest=2;
	int highest=75; 
    int range=(highest-lowest)+1; 

    for(int i=0; i<29; i++){ 
    // Initialize random number generator.
	r=rand()/100%range+lowest;
    //r = rand() % 100 + 1;
	//  r = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
	arrX[i] = r;
	//cout << "Xpos: " << arrX[i] << "-" << i << "-- " << "\n";
	} // end of for loop
	return arrX;
}
//********************************************************************************************
// int* generateYPosition() 
// This method is used to generate a random number between 1-23 to generate an Y coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of ints.
//********************************************************************************************
int* generateYPosition()
{
    //int i=0;
	int r;
	int *arrY = new int[30];  
//    r = (((( rand() % 10) * 10));
     srand(time(0));
	int lowest=2;
	int highest=17; 
    int range=(highest-lowest)+1; 

    for(int i=0; i<30; i++){ 
       // Initialize random number generator.
	  r=rand()/100%range+lowest;
		//r = lowest+int(range*rand()/(RAND_MAX)); 
	  arrY[i] = r;
	//  cout << "Ypos " << r << "-" << i << "-- " << "\n";
	} // end of for loop
	return arrY;
}

//********************************************************************************************
// void travel 
// This method receives a int (the option you enter) and also a reference to the ship object
// which is passed and then modified in the switch statement and then returned.
//********************************************************************************************
void travel(int t, ship &s)
{
   switch (t)
   {
   //case 0:
//	   cout << "Welcome to the shop we are under construction..." << endl;
  /*     break;
   case 1:
	if (s.getX()!=POSITIVE_XLIMIT)
	{
    	s.setX(s.getX()+1);
		s.setFuel(s.getFuel()-2);
	}
	else
	{

	}
	   break;
   case 2:
	   if (s.getX()!=NEGATIVE_XLIMIT)
	   {
	   s.setX(s.getX()-1);
	   s.setFuel(s.getFuel()-2);
	   }
	   else
	   {}
	   break;
   case 3:
	   if (s.getY()!=POSITIVE_YLIMIT)
	   {
	   s.setY(s.getY()+1);
	   s.setFuel(s.getFuel()-2);
	   }
	   else
	   {}
	   break;
   case 4:
	   if (s.getY()!=NEGATIVE_YLIMIT)
	   {
	   s.setY(s.getY()-1);
	   s.setFuel(s.getFuel()-2);
	   }
	   else
	   {}
	   break;
*/
  case 8:
       cout << "\nGood by and thank you for playing!" << endl;
	   break;
   default: cout << t << " is not a valid entry..." << endl;
   } // end of case
   // cout << "Your Location in space is: " << s.getX() << ", " << s.getY() << ", " << s.getZ() << endl;
   //cout << "Your Location in space is: " << s.getX() << ", " << s.getY() << endl;
   // made redundant by the HUD
}
//**********************************************************************************
// void generatePlanets()
// This method generates and returns an a pointer to a char array of planets.
//**********************************************************************************
/*
void generatePlanets()
{

	//char planets = new char *[UNIVERSE_ARRAY_SIZE];
	planetArray = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Neptune", "Uranus", "Pluto" };
 
  }
  */
//***********************************************************************************
// void drawMap()  
// This is a simple function to draw out the physical map of the universe
// This function receives all the planet objects passed in so it can map them as well 
// your ship position
//**********************************************************************************
void drawMap(int shipX, int shipY, int jupiterX, int jupiterY,int earthX, int earthY, int marsX, int marsY,int ganymedeX,int ganymedeY,int moonX, int moonY,int saturnX, int saturnY,int neptuneX, int neptuneY, int plutoX, int plutoY,int ceresX, int ceresY, int sunX, int sunY, int beltegeuseX, int beltegeuseY )
{
int ship_X=0;
int ship_Y=0;
int jupiter_X =0;
int jupiter_Y=0;
int earth_X=0;
int earth_Y=0;
int mars_X=0;
int mars_Y=0;
int ganymede_X=0;
int ganymede_Y=0;
int moon_X=0;
int moon_Y=0;
int saturn_X=0;
int saturn_Y=0;
int neptune_X=0;
int neptune_Y=0;
int pluto_X=0;
int pluto_Y=0;
int ceres_X=0;
int ceres_Y=0;
//int

   char array[21][81] = {
    "0-+-+-+-+-1-+-+-+-+-2-+-+-+-+-3-+-+-+-+-4-+-+-+-+-5-+-+-+-+-6-+-+-+-+-7-+-+-+-+",
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "1                                                                             1",    
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "+                                                                             +",
    "-                                                                             -",
    "+                                                                             +",    
    "-                                                                             -",
    "0-+-+-+-+-1-+-+-+-+-2-+-+-+-+-3-+-+-+-+-4-+-+-+-+-5-+-+-+-+-6-+-+-+-+-7-+-+-+-+"};

 ship_X = (int) shipX;
 ship_Y = (int) shipY;
 jupiter_X = (int) jupiterX;
 jupiter_Y = (int) jupiterY;
 earth_X = (int) earthX;
 earth_Y = (int) earthY;
 mars_X = (int) marsX;
 mars_Y = (int) marsY;
 ganymede_X = (int) ganymedeX;
 ganymede_Y = (int) ganymedeY;
 moon_X  = (int) moonX;
 moon_Y  = (int) moonY;
 saturn_X  = (int) saturnX;
 saturn_Y  = (int) saturnY;
 neptune_X  = (int) neptuneX;
 neptune_Y  = (int) neptuneY;
 pluto_X  = (int) plutoX;
 pluto_Y  = (int) plutoY;
 ceres_X  = (int) ceresX;
 ceres_Y  = (int) ceresY;
// sun_X    = sunX;
// sun_Y    = sunY;

  array[ship_Y][ship_X]= 'x';
  array[jupiter_Y][jupiter_X]= 'J';
  array[earth_Y][earth_X] = 'E';
  array[mars_Y][mars_X]= 'M';
  array[ganymede_Y][ganymede_X]= 'g';
  array[moon_Y][moon_X]= 'm';
  array[saturn_Y][saturn_X]= 'S';
  array[neptune_Y][neptune_X]= 'N';
  array[pluto_Y][pluto_X]= 'P';
  array[ceres_Y][ceres_X]= 'C';
 // array[sunX][sunY] = 's';
 // array[beltegeuseX][beltegeuseY] = 'B';

  // watch out!!! I had the bounds backwards and since c++ doesn't check the prog
  // complied but then crashed when I tried to assign a value.
  // also the subscripts need to be int - so cast the ints!!! or else crash city
 //cout << ex;
   // cout << array[3][81];

    for (int i = 0; i < 21; i++){
        for (int j = 0; j < 80; j++){
            cout << array[i][j] ;
            }
 

}
}
//***********************************************************************************
// void drawHUD()  
// This is a simple function to draw out the text description of where you are
// 
// 
//**********************************************************************************
int drawHUD(int mx, int my, ship &s)
{
 
  string asciiPos;	 
  string stringX;
  string stringY;
  int eight=8;
  int input=0;

   cout << "The Moon (m), your home base is located at: "; 
   SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
   cout << mx << ", " << my << " - You are located at: " << s.getX() << ", " << s.getY();
   SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
   cout << "\nStatus - Fuel: " << s.getFuel() << " Spacebucks: " << s.getFunds() << endl;
   cout << "Cargo Hold: Rice: " << s.getRice() << " IRON: " << s.getIron() << " SUGAR: " << s.getSugar() << endl;
   //cout << "What do you want to do? (1 +x 2 -x 3 +y 4 -y -- 8 is quit) ";
   cout << "Where do you want to move? (XX,YY -- 8 is quit) ";
   cin >> asciiPos;
   
// error cehcking for input

   	outfile.open("inputLog.txt", ios::app);
	outfile  << "The time is: " << asctime(localtm) << " " << "asciiPos: " << asciiPos << endl;
    outfile.close();
//  ---------------

   stringX=asciiPos.substr(0,2);
   stringY=asciiPos.substr(3,5);

   parseMovement(stringX,stringY,s);
   //parseStringY(stringY,s.getY());

   if (atoi(asciiPos.c_str()) == eight)
   {
   input=8;
   }
   else
   {
	   // Input is coming in a format of XX,YY a five char string
	   // it is beingsplit assuming that the input is two chars comma and two more
	   //  each value is being assigned to the x,y value - which is strange because I think
	   //  the x,y value is opposite anyway. =P
	
  // s.setX(atoi(stringX.c_str()));  // must cast the string into an integer so that you can repostion your ship
   //s.setY(atoi(stringY.c_str()));  // ditto	
   }
   return input;
}
//***********************************************************************************
// int parseStringX()  
// This is a simple function to parse and return the coodinates you want to goto
// 
// 
//**********************************************************************************
void parseMovement(string strX,string strY,ship &s)
{
   int x;
   int y;
   double hypot=0.0;

    

 
   x = atoi(strX.c_str());
   y = atoi(strY.c_str());
  

   if (x == 0)
   {
	s.setX(s.getX());
   }
  
   if (y == 0)
   {
	s.setY(s.getY());
   }


   if (x <= POSITIVE_XLIMIT && x >= NEGATIVE_XLIMIT && y <= POSITIVE_YLIMIT && y >= NEGATIVE_YLIMIT)
  {
  // calculate data for hypotenuese (sp?) and get units for fuel subtraction
   double xc = x-s.getX();
   double yc = y-s.getY();
  
   double xcsq = xc*xc;
   double yxsq = yc*yc;

   double hypot = abs(sqrt(xcsq+yxsq));
	  // error checking for input
	outfile.open("errorLog.txt", ios::app);
	outfile  << "The time is: " << asctime(localtm) << " " << "Hypotenoose: " << hypot << endl;
    outfile.close();
     // ------
	  s.setX(x);  // 
	  s.setY(y);
  
	  s.setFuel(s.getFuel()-hypot);
  }

 

} // end of method
//********************************************************************************************
// int* generateXPosition() 
// This method is used to generate a random number between 1-80 to generate an X coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of ints.
//********************************************************************************************
int* generateCosts()
{
	int r=0;
	int *costArr = new int[30];

    
    srand(time(0));
	int lowest=1;
	int highest=100; 
    int range=(highest-lowest)+1; 

    for(int i=0; i<29; i++){ 
       // Initialize random number generator.
	  r = lowest+int(range*rand()/(RAND_MAX + 1.0)); 
	  costArr[i] = r;
	} // end of for loop
	return costArr;
}
//********************************************************************************************
// int moveMoon() 
// This method is used to run a counter that makes the moon orbit earth every couple of turns.
//
//********************************************************************************************
void moveMoon(planet &m)
{

static int moonCounter;
// counter to move the moon;
  moonCounter++;
switch (moonCounter)
{
		case 5:
			// move moon right (1) space
			m.setX(m.getX()+1);
			break;
		case 10:
			// move moon right (1) space
			m.setX(m.getX()+1);
			break;
		case 15:
 			// move moon up (1) space
			m.setY(m.getY()-1);
			break;
		case 20:
 			// move moon up (1) space
			m.setY(m.getY()-1);
			break;
		case 25:
 			// move moon up (1) space
			m.setY(m.getY()-1);
			break;
		case 30:
 			// move moon up (1) space
			m.setY(m.getY()-1);
			break;
		case 35:
  			// move moon left (-1) space
			m.setX(m.getX()-1);
			break;
		case 40:
  			// move moon left (-1) space
			m.setX(m.getX()-1);
			break;
		case 45:
  			// move moon left (-1) space
			m.setX(m.getX()-1);
			break;
		case 50:
  			// move moon left (-1) space
			m.setX(m.getX()-1);
			break;	 
		case 55:
 			// move moon up (1) space
			m.setY(m.getY()+1);
			break;
		case 60:
 			// move moon up (1) space
			m.setY(m.getY()+1);
			break;
		case 65:
 			// move moon up (1) space
			m.setY(m.getY()+1);
			break;
		case 70:
 			// move moon up (1) space
			m.setY(m.getY()+1);
			break;
		case 75:
			// move moon right (1) space
			m.setX(m.getX()+1);
			break;
		case 80:
			// move moon right (1) space
			m.setX(m.getX()+1);
			moonCounter=0;
			break;		
		default:
			;
		}


}           

//********************************************************************************************
// int checkIfAtPlanetMenu() 
// This method is used when you get to a planet to generate the buy and sell option
// as of right now the planet.getPlanetName() is giving errors so it is left blank
//********************************************************************************************
int checkIfAtPlanetMenu(ship &s,planet &p)
{
  int input = 0;

	   system("cls");
	   cout << "Welcome to --Fix Planet Name--... " << "Planet Description goes here?? Maybe?." << endl << endl;
	   cout << "\nIron: " << p.getIronQuantity() << endl;
	   cout << "\nSugar: " << p.getSugarQuantity() << endl;
	   cout << "\nRice: " << p.getRiceQuantity() << endl;
	   cout << "\nFuel: " << p.getFuel() << endl;
	   cout << "1. Buy Iron: " << endl;
	   cout << "2. Buy Sugar: " << endl;
	   cout << "3. Buy Rice: " << endl;
	   cout << "4. Sell Iron: " << endl;
	   cout << "5. Sell Sugar: " << endl;
	   cout << "6. Sell Rice: " << endl;
	   cout << "7. Buy Fuel: " << endl;
	   cout << "8. Exit planet" << endl;
	   cout << "You have " << "Rice - " << s.getRice() << " Iron - " << s.getIron() << " Sugar - " << s.getSugar() << endl;
	   cout	<< "SpaceBucks - " << s.getFunds() << " Fuel - " << s.getFuel() << " Cargo Max - " << s.getCARGO_MAX() << endl;
       cout << "What do you want to do?";
       
       cin >> input;
return input;
}
//********************************************************************************************
// void checkIfAtMoonMenu() 
// This method is used to start the game at your home base of the moon
// This can be changed.
//********************************************************************************************
int checkIfAtMoonMenu(ship &s,planet &j,planet &e,planet &m,planet &g,planet &M,planet &S,planet &n,planet &p,planet &c)
{
  int input = 0;

	   system("cls");
	   cout << "Welcome to the Moon, your home base " << "Planet Description goes here?? Maybe?." << endl << endl;
	   cout << ":::Space News::: " <<  endl;
	   cout << "Planet   " << "Iron" << "\t" << "Price" << "\t" << "Sugar" << "\t" << "Price" << "\t" << "Rice" << "\t" << "Price" << endl;
	  // cout << "Jupiter  " <<  << "\t" << j.getIronQuantityDesired() << "\t" << j.getSugar() << "\t" << j.getSugarPrice()  << "\t" << j.getRice() << "\t" << j.getRicePrice() << endl;
	  // cout << "Earth    " << << "\t" << e.getIronQuantityDesired() << "\t" << e.getSugar() << "\t" << e.getSugarPrice()  << "\t" << e.getRice() << "\t" << e.getRicePrice() << endl;
	 //  cout << "Ganymede " << g.getIronQuantity() << "\t" << g.getIronQuantityDesired() << "\t" << g.getSugar() << "\t" << g.getSugarPrice()  << "\t" << g.getRice() << "\t" << g.getRicePrice() << endl;
	 //  cout << "Mars     " << m.getIronQuantity() << "\t" << m.getIronQuantityDesired() << "\t" << m.getSugar() << "\t" << m.getSugarPrice()  << "\t" << m.getRice() << "\t" << m.getRicePrice() << endl;
	 //  cout << "Saturn   " << S.getIronQuantity() << "\t" << S.getIronQuantityDesired() << "\t" << S.getSugar() << "\t" << S.getSugarPrice()  << "\t" << S.getRice() << "\t" << S.getRicePrice() << endl;
	 //  cout << "Neptune  " << n.getIronQuantity() << "\t" << n.getIronQuantityDesired() << "\t" << n.getSugar() << "\t" << n.getSugarPrice()  << "\t" << n.getRice() << "\t" << n.getRicePrice() << endl;
	//   cout << "Pluto    " << p.getIronQuantity() << "\t" << p.getIronQuantityDesired() << "\t" << p.getSugar() << "\t" << p.getSugarPrice()  << "\t" << p.getRice() << "\t" << p.getRicePrice() << endl;
	//   cout << "Ceres    " << c.getIronQuantity() << "\t" << c.getIronQuantityDesired() << "\t" << c.getSugar() << "\t" << c.getSugarPrice()  << "\t" << c.getRice() << "\t" << c.getRicePrice() << endl;
	   //cout << "Jupiter" << j.getIronQuantity() << "\t" << j.getIronQuantityDesiredQuantity() << "\t" << j.getSugar() << "\t" << j.getSugarPrice()  << "\t" << j.getRice() << "\t" << j.getRicePrice() << endl;
       cout << endl; 
	  // cout << "\nRice: " << p.getRice() << endl;
	   //cout << "\nFuel: " << p.getFuel() << endl;
	   cout << "1. Check Mail Box: -- Not Functional... " << endl;
	   cout << "2. Repair Ship: -- Not Functional... " << endl;
	   cout << "3. Upgrade Ship: -- Not Functional... " << endl;
	   cout << "4. Pick Up Passengers: -- Not Functional... " << endl;
	   cout << "5. Talk to people listen to space news... -- not functional... " << endl;
	   cout << "6. Leave Space Station... -- This works!" << endl;
	   cout << endl;

	   cout << "You have " << "Rice - " << s.getRice() << " Iron - " << s.getIron() << " Sugar - " << s.getSugar() << endl;
	   cout	<< "SpaceBucks - " << s.getFunds() << " Fuel - " << s.getFuel() << " Cargo Max - " << s.getCARGO_MAX() << endl;
       cout << "What do you want to do?";
       
       cin >> input;
return input;
}