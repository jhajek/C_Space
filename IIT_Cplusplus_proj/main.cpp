#include<iostream>
#include "unit.h"
#include "planet.h"
#include "ship.h"
#include "origen.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <windows.h>
#include <string>
#include <cctype>

using namespace std; 

const short POSITIVE_XLIMIT=77;
const short NEGATIVE_XLIMIT=1;
const short POSITIVE_YLIMIT=19;
const short NEGATIVE_YLIMIT=1;
const short PLANET_NAME_SIZE=9;
const short UNIVERSE_ARRAY_SIZE=9;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

short* generateXPosition();
short* generateYPosition();
void travel(short,ship &);
short* generateCosts();
//void generatePlanets();
void drawMap(short,short, short, short, short, short,short,short,short,short,short,short, short, short,short,short,short,short,short,short);
short drawHUD(short, short, ship &);
void checkIfAtPlanet(ship &,planet &,planet &, planet &,planet &,planet &, planet &,planet &,planet &, planet &);
void moveMoon(planet &);
void buyIron(ship &,planet &);
void buyRice(ship &,planet &);
void buySugar(ship &,planet &);
void buyFuel(ship &,planet &);
void sellIron(ship &,planet &);
short checkIfAtPlanetMenu(ship &, planet &);
short checkIfAtMoonMenu(ship &,planet &,planet &, planet &,planet &,planet &, planet &,planet &,planet &, planet &);
void randomEvent();
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
	
   short *arrX=0;
   short *arrY=0;
   short *costArray=0;
   short input=0;
   short moonCounter=0;
   short number_of_planets=0;
   short movePosition=0;
//   short moonCounter=0;
   arrX = generateXPosition();
   arrY = generateYPosition();
   costArray = generateCosts();
// create 9 planets
   planet jupiter(36,(*(arrY+1)),"Juptier",2000,6000,5000,4000,20000,(*(costArray+3)),(*(costArray+4)),(*(costArray+5)),(*(costArray+24)));
   planet earth (12,(*(arrY)),"Earth",25000,10000,500,500,5000,(*(costArray)),(*(costArray+1)),(*(costArray+2)),(*(costArray+24)));
   planet mars (3,(*(arrY+2)),"Mars",7000,0,700,200,0,(*(costArray+6)),(*(costArray+7)),(*(costArray+8)),(*(costArray+24)));
   planet ganymede (jupiter.getX()+0,jupiter.getY()+2,"Ganymede",5000,4000,1000,0,500,(*(costArray+9)),(*(costArray+10)),(*(costArray+11)),(*(costArray+24)));
   planet moon(earth.getX()+0,earth.getY()+2,"Moon",0,0,0,0,0,0,0,0,0);
   planet saturn (24,(*(arrY+3)),"Saturn",(*(costArray+15)*10),6000,5000,4000,20000,(*(costArray+12)),(*(costArray+13)),(*(costArray+14)),(*(costArray+24)));
   planet neptune (48,(*(arrY+4)),"Neptune",2000,6000,5000,(*(costArray+9)*10),20000,(*(costArray+15)),(*(costArray+16)),(*(costArray+17)),(*(costArray+24)));
   planet pluto (60,(*(arrY+5)),"Pluto",2000,1000,200,6000,700,(*(costArray+18)),(*(costArray+19)),(*(costArray+20)),(*(costArray+24)));
   planet ceres (72,(*(arrY+6)),"Ceres",1000,5000,3000,4000,7000,(*(costArray+21)),(*(costArray+22)),(*(costArray+23)),(*(costArray+24)));

   ship s(moon.getX(),moon.getY(),"Enterprise",500,10000,0,0,200,5000);

  
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
   drawMap(s.getX(),s.getY(),jupiter.getX(),jupiter.getY(),earth.getX(),earth.getY(),mars.getX(),mars.getY(),ganymede.getX(),ganymede.getY(),moon.getX(),moon.getY(),saturn.getX(),saturn.getY(),neptune.getX(),neptune.getY(),pluto.getX(),pluto.getY(),ceres.getX(),ceres.getY());
   input = drawHUD(moon.getX(),moon.getY(),s);
   travel(input,s);
   moveMoon(moon);
   system("cls");
   } // end of main while loop

   return 0;
} 
//********************************************************************************************
// short* generateXPosition() 
// This method is used to generate a random number between 1-80 to generate an X coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of shorts.
//********************************************************************************************
short* generateXPosition()
{
    //int i=0;
	int r;
	short *arrX = new short[30];

    
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
// short* generateYPosition() 
// This method is used to generate a random number between 1-23 to generate an Y coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of shorts.
//********************************************************************************************
short* generateYPosition()
{
    //int i=0;
	int r;
	short *arrY = new short[30];  
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
// This method receives a short (the option you enter) and also a reference to the ship object
// which is passed and then modified in the switch statement and then returned.
//********************************************************************************************
void travel(short t, ship &s)
{
   switch (t)
   {
   //case 0:
//	   cout << "Welcome to the shop we are under construction..." << endl;
  //     break;
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
/*   case 5:
	   if (s.getZ()!=POSITIVE_LIMIT)
	   {
	   s.setZ(s.getZ()+10);
	   }
	   else
	   {}
	   break;
   case 6:
	   if (s.getZ()!=NEGATIVE_LIMIT)
	   {
	   s.setZ(s.getZ()-10);
	   }
	   else
	   {}
	   break;
  */  // reserved for 3D
//	case 7:
//	   cout << "\n Fuel is at: " << s.getFuel() << endl;
//	   cout << " Funds are at: " << s.getFunds() << endl;
	  // cout << " Shipname is : " << s.getShipName() << "\n" << endl;
  //     break;
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
void drawMap(short shipX, short shipY, short jupiterX, short jupiterY,short earthX, short earthY, short marsX, short marsY,short ganymedeX,short ganymedeY,short moonX, short moonY,short saturnX, short saturnY,short neptuneX, short neptuneY, short plutoX, short plutoY,short ceresX, short ceresY )
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

  // watch out!!! I had the bounds backwards and since c++ doesn't check the prog
  // complied but then crashed when I tried to assign a value.
  // also the subscripts need to be int - so cast the shorts!!! or else crash city
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
short drawHUD(short mx, short my, ship &s)
{
 
//  char* ascii_input=' ';	 
  short input=0;

   cout << "The Moon (m), your home base is located at: "; 
   SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
   cout << mx << ", " << my << " - You are located at: " << s.getX() << ", " << s.getY();
   SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
   cout << "\nStatus - Fuel: " << s.getFuel() << " Spacebucks: " << s.getFunds() << endl;
   cout << "Cargo Hold: Rice: " << s.getRice() << " IRON: " << s.getIron() << " SUGAR: " << s.getSugar() << endl;
   cout << "What do you want to do? (1 +x 2 -x 3 +y 4 -y -- 8 is quit) ";
   cin >> input;

   return input;
   // return ascii_input;
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
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,jupiter);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,jupiter);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,jupiter);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,jupiter);
		   break;
       case 4:
     	   system("cls");
           buyFuel(s,jupiter);
		   break;
	   case 5:
     	   system("cls");
           sellIron(s,jupiter);
		   break;
/*	   case 6:
     	   system("cls");
           sellSugar(s,jupiter);
		   break;
	   case 7:
     	   system("cls");
           sellRice(s,jupiter);
		   break;
*/
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
    }  // end of jupiter if
//**********************************************************************************
// 2. Earth
//**********************************************************************************
      if (s.getX()==earth.getX() && s.getY()==earth.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,earth);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,earth);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,earth);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,earth);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 3. Mars
//**********************************************************************************
	     if (s.getX()==mars.getX() && s.getY()==mars.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,mars);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,mars);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,mars);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,mars);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 4. Ganymede
//**********************************************************************************
   if (s.getX()==ganymede.getX() && s.getY()==ganymede.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,ganymede);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,ganymede);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,ganymede);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,ganymede);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 5. Saturn
//**********************************************************************************
   if (s.getX()==saturn.getX() && s.getY()==saturn.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,saturn);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,saturn);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,saturn);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,saturn);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 6. Pluto
//**********************************************************************************
	     if (s.getX()==pluto.getX() && s.getY()==pluto.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,pluto);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,pluto);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,pluto);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,pluto);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 7. Ceres
//**********************************************************************************
		 
		 if (s.getX()==ceres.getX() && s.getY()==ceres.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,ceres);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,ceres);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,ceres);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,ceres);
		   break;
	   default:
		     cout << "You can only choose option 1-3 to buy for now, nothing else is programmed... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
    }
//**********************************************************************************
// 8. Neptune
//**********************************************************************************
		 
		 if (s.getX()==neptune.getX() && s.getY()==neptune.getY())
   {
	   
	  do 	
	  { // begin do loop
	   
	   input = checkIfAtPlanetMenu(s,neptune);	  
         
       switch(input)
	   {
	   case 1: 
		   system("cls");
           buyIron(s,neptune);   
		   break;
	   case 2:
     	   system("cls");
           buySugar(s,neptune);
		   break;
	   case 3:
     	   system("cls");
           buyRice(s,neptune);
		   break;
	   case 4: 
		   system("cls");
		   sellIron(s,neptune);
		   break;
/*	   case 5: 
		   system("cls");
		   sellSugar(s,neptune);
		   break;
	   case 6: 
		   system("cls");
		   sellRice(s,neptune);
		   break;
		   */
	   default:
		     cout << "6 options working... " << endl;
		     break;
	   }// end of switch
       		  
	  } // end of do
	   while (input == 1 || input == 2 || input == 3  || input == 4 || input == 5 || input == 6 || input == 7);
	   s.setX(s.getX()+1);
 
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


} // end of method
//********************************************************************************************
// short* generateXPosition() 
// This method is used to generate a random number between 1-80 to generate an X coord
//  30 postions are calculated and then returned in an array.  Returns a pointer to an 
// array of shorts.
//********************************************************************************************
short* generateCosts()
{
	int r=0;
	short *costArr = new short[30];

    
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
// short moveMoon() 
// This method is used to run a counter that makes the moon orbit earth every couple of turns.
//
//********************************************************************************************
void moveMoon(planet &m)
{

static short moonCounter;
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
// void buyIron() 
// This method is used for all the commerce, you just pass it a planet for adding and subtracting
// iron.
//********************************************************************************************
void buyIron(ship &s,planet &p)
{
   short quantity_to_buy=0;
   short cargo_space_left=0;
   short cargo_total=0;

	
	cout << "Iron Quantity --Fix planet Name!!: \n" << "Units of Iron for sale: " << p.getIron() << "\nIron price per unit: " << p.getIronPrice() << endl;
		      cout << "Your Funds left: " << s.getFunds() << " Your current cargo: Rice: " << s.getRice() << " Iron: " << s.getIron() << " Sugar: " << s.getSugar() << endl; 
			  cargo_space_left = (s.getCARGO_MAX() - (s.getIron()+s.getRice()+s.getSugar()));
			  cout << "Total Cargo Space left = " << cargo_space_left << endl << endl; 
			  cout << "How much Iron to buy: " << endl; 
			  cin >> quantity_to_buy;
			  // this is one big error checking algorthym which needs to be split into three embedded ifs for more specific error 
			  // checking, otherwise it just will fail and you'll only have a general idea of why.
			  
              cargo_total = s.getIron()+s.getRice()+s.getSugar()+quantity_to_buy;

			  if (quantity_to_buy <= p.getIron() && s.getFunds() >= (p.getIronPrice() * quantity_to_buy) && cargo_total <= s.getCARGO_MAX())
			  {
		         p.setIron(p.getIron()-quantity_to_buy); // subtracts amount of iron purchased
				 p.setFunds(p.getFunds()+(quantity_to_buy*p.getIronPrice())); // adds cost of purchase to jupiter account
				 
				 s.setFunds(s.getFunds()-(quantity_to_buy*p.getIronPrice())); // subtract cost purchased of what you bought
				 s.setIron(s.getIron()+quantity_to_buy); // adds amount of iron you bought
			  }
			  else
			  {
				  cout << "some error occured..." << endl;
			  }



}
//********************************************************************************************
// void buySugar() 
// This method is used for all the commerce, you just pass it a planet for adding and subtracting
// sugar.
//********************************************************************************************
void buySugar(ship &s,planet &p)
{

   short input = 0;
   short quantity_to_buy=0;
   short cargo_space_left=0;
   short cargo_total=0;

	
	cout << "Sugar Quantity for: --Fix Planet Name function - not working!!!- " /*<< p.getPlanetName() <<*/ << " " << p.getSugar() << " Sugar price per unit: " << p.getSugarPrice() << endl;
	cout << "Your Funds left: " << s.getFunds() << " Your current cargo: Rice: " << s.getRice() << " Iron: " << s.getIron() << " Sugar: " << s.getSugar() << endl; 
	cargo_space_left = (s.getCARGO_MAX() - (s.getIron()+s.getRice()+s.getSugar()));
	cout << " Total Cargo Space left = " << cargo_space_left << endl << endl; 
	cout << "How much Sugar to buy: " << endl; 
	cin >> quantity_to_buy;
	// this is one big error checking algorthym which needs to be split into three embedded ifs for more specific error 
	// checking, otherwise it just will fail and you'll only have a general idea of why.
			  
    cargo_total = s.getSugar()+s.getRice()+s.getSugar()+quantity_to_buy;

	if (quantity_to_buy <= p.getSugar() && s.getFunds() >= (p.getSugarPrice() * quantity_to_buy) && cargo_total <= s.getCARGO_MAX())
	{
		p.setSugar(p.getSugar()-quantity_to_buy); // subtracts amount of iron purchased
		p.setFunds(p.getFunds()+(quantity_to_buy*p.getSugarPrice())); // adds cost of purchase to jupiter account
				 
		s.setFunds(s.getFunds()-(quantity_to_buy*p.getSugarPrice())); // subtract cost purchased of what you bought
		s.setSugar(s.getSugar()+quantity_to_buy); // adds amount of iron you bought
	}
    else
	{
		 cout << "some error occured..." << endl;
	}




} // end of buy sugar
//********************************************************************************************
// void buyRice() 
// This method is used for all the commerce, you just pass it a planet for adding and subtracting
// rice.
//********************************************************************************************
void buyRice(ship &s,planet &p)
{

   short input = 0;
   short quantity_to_buy=0;
   short cargo_space_left=0;
   short cargo_total=0;

	
	cout << "RICE Quantity for: --Fix Planet Name function!!! " << /*p.getPlanetName() <<*/ " " << p.getRice() << " Rice price per unit: " << p.getRicePrice() << endl;
	cout << "Your Funds left: " << s.getFunds() << " Your current cargo: Rice: " << s.getRice() << " Iron: " << s.getIron() << " Sugar: " << s.getSugar() << endl; 
	cargo_space_left = (s.getCARGO_MAX() - (s.getIron()+s.getRice()+s.getSugar()));
	cout << "Total Cargo Space left = " << cargo_space_left << endl << endl; 
	cout << "How much RICE to buy: " << endl; 
	cin >> quantity_to_buy;
	// this is one big error checking algorthym which needs to be split into three embedded ifs for more specific error 
	// checking, otherwise it just will fail and you'll only have a general idea of why.
			  
    cargo_total = s.getIron()+s.getRice()+s.getSugar()+quantity_to_buy;

	if (quantity_to_buy <= p.getRice() && s.getFunds() >= (p.getRicePrice() * quantity_to_buy) && cargo_total <= s.getCARGO_MAX())
	{
		p.setRice(p.getRice()-quantity_to_buy); // subtracts amount of iron purchased
		p.setFunds(p.getFunds()+(quantity_to_buy*p.getRicePrice())); // adds cost of purchase to jupiter account
				 
		s.setFunds(s.getFunds()-(quantity_to_buy*p.getRicePrice())); // subtract cost purchased of what you bought
		s.setRice(s.getRice()+quantity_to_buy); // adds amount of iron you bought
	}
    else
	{
		 cout << "some error occured..." << endl;
	}
} // end of buy sugar
//********************************************************************************************
// void buyFuel() 
// This method is used for all the commerce, you just pass it a planet for adding and subtracting
// fuel.
//********************************************************************************************
void buyFuel(ship &s,planet &p)
{
   short quantity_to_buy=0;
   short cargo_space_left=0;
   short cargo_total=0;

	
	cout << "Fuel Quantity --Fix planet Name!!: \n" << "Units of Fuel for sale: " << p.getFuel() << "\nFuel price per unit: " << p.getFuelPrice() << endl;
		      cout << "Your Funds left: " << s.getFunds() << " Your current cargo: Rice: " << s.getRice() << " Iron: " << s.getIron() << " Sugar: " << s.getSugar() << endl; 
			  cargo_space_left = (s.getCARGO_MAX() - (s.getIron()+s.getRice()+s.getSugar()));
			  cout << "Total Cargo Space left = " << cargo_space_left << endl << endl; 
			  cout << "How much Fuel to buy: " << endl; 
			  cin >> quantity_to_buy;
			  // this is one big error checking algorthym which needs to be split into three embedded ifs for more specific error 
			  // checking, otherwise it just will fail and you'll only have a general idea of why.
			  
              cargo_total = s.getIron()+s.getRice()+s.getSugar()+quantity_to_buy;

			  if (quantity_to_buy <= p.getFuel() && s.getFunds() >= (p.getFuelPrice() * quantity_to_buy) && cargo_total <= s.getCARGO_MAX())
			  {
		         p.setFuel(p.getFuel()-quantity_to_buy); // subtracts amount of Fuel purchased
				 p.setFunds(p.getFunds()+(quantity_to_buy*p.getIronPrice())); // adds cost of purchase to jupiter account
				 
				 s.setFunds(s.getFunds()-(quantity_to_buy*p.getIronPrice())); // subtract cost purchased of what you bought
				 s.setFuel(s.getFuel()+quantity_to_buy); // adds amount of Fuel you bought
			  }
			  else
			  {
				  cout << "some error occured..." << endl;
			  }



}
//********************************************************************************************
// void sellIron() 
// This method is used for all the commerce, you just pass it a planet for adding and subtracting
// Iron.
//********************************************************************************************
void sellIron(ship &s,planet &p)
{

   short input = 0;
   short quantity_to_sell=0;
   short cargo_space_left=0;
   short cargo_total=0;

	
	cout << "RICE Quantity for: --Fix Planet Name function!!! " << /*p.getPlanetName() <<*/ " " << p.getIron() << " Iron price per unit: " << p.getIronPrice() << endl;
	cout << "Your Funds left: " << s.getFunds() << " Your current cargo: Rice: " << s.getRice() << " Iron: " << s.getIron() << " Sugar: " << s.getSugar() << endl; 
	cargo_space_left = (s.getCARGO_MAX() - (s.getIron()+s.getRice()+s.getSugar()));
	cout << "Total Cargo Space left = " << cargo_space_left << endl << endl; 
	cout << "How much Iron to sell: " << endl; 
	cin >> quantity_to_sell;
	// this is one big error checking algorthym which needs to be split into three embedded ifs for more specific error 
	// checking, otherwise it just will fail and you'll only have a general idea of why.
			  
    cargo_total = s.getIron()+s.getRice()+s.getSugar()+quantity_to_sell;

	if (quantity_to_sell <= p.getIron() && s.getFunds() >= (p.getIronPrice() * quantity_to_sell) && cargo_total <= s.getCARGO_MAX())
	{
		p.setIron(p.getIron()+quantity_to_sell); // adds amount of iron planet purchased
		p.setFunds(p.getFunds()-(quantity_to_sell*p.getIronPrice())); // subtracts cost of purchase to planet account
				 
		s.setFunds(s.getFunds()+(quantity_to_sell*p.getIronPrice())); // add money 
		s.setRice(s.getIron()-quantity_to_sell); // subtracts amount of iron you sold
	}
    else
	{
		 cout << "some error occured..." << endl;
	}
} // end of sell Iron
//********************************************************************************************
// short checkIfAtPlanetMenu() 
// This method is used when you get to a planet to generate the buy and sell option
// as of right now the planet.getPlanetName() is giving errors so it is left blank
//********************************************************************************************
short checkIfAtPlanetMenu(ship &s,planet &p)
{
  short input = 0;

	   system("cls");
	   cout << "Welcome to --Fix Planet Name--... " << "Planet Description goes here?? Maybe?." << endl << endl;
	   cout << "\nIron: " << p.getIron() << endl;
	   cout << "\nSugar: " << p.getSugar() << endl;
	   cout << "\nRice: " << p.getRice() << endl;
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
short checkIfAtMoonMenu(ship &s,planet &j,planet &e,planet &m,planet &g,planet &M,planet &S,planet &n,planet &p,planet &c)
{
  short input = 0;

	   system("cls");
	   cout << "Welcome to the Moon, your home base " << "Planet Description goes here?? Maybe?." << endl << endl;
	   cout << ":::Space News::: " <<  endl;
	   cout << "Planet   " << "Iron" << "\t" << "Price" << "\t" << "Sugar" << "\t" << "Price" << "\t" << "Rice" << "\t" << "Price" << endl;
	   cout << "Jupiter  " << j.getIron() << "\t" << j.getIronPrice() << "\t" << j.getSugar() << "\t" << j.getSugarPrice()  << "\t" << j.getRice() << "\t" << j.getRicePrice() << endl;
	   cout << "Earth    " << e.getIron() << "\t" << e.getIronPrice() << "\t" << e.getSugar() << "\t" << e.getSugarPrice()  << "\t" << e.getRice() << "\t" << e.getRicePrice() << endl;
	   cout << "Ganymede " << g.getIron() << "\t" << g.getIronPrice() << "\t" << g.getSugar() << "\t" << g.getSugarPrice()  << "\t" << g.getRice() << "\t" << g.getRicePrice() << endl;
	   cout << "Mars     " << m.getIron() << "\t" << m.getIronPrice() << "\t" << m.getSugar() << "\t" << m.getSugarPrice()  << "\t" << m.getRice() << "\t" << m.getRicePrice() << endl;
	   cout << "Saturn   " << S.getIron() << "\t" << S.getIronPrice() << "\t" << S.getSugar() << "\t" << S.getSugarPrice()  << "\t" << S.getRice() << "\t" << S.getRicePrice() << endl;
	   cout << "Neptune  " << n.getIron() << "\t" << n.getIronPrice() << "\t" << n.getSugar() << "\t" << n.getSugarPrice()  << "\t" << n.getRice() << "\t" << n.getRicePrice() << endl;
	   cout << "Pluto    " << p.getIron() << "\t" << p.getIronPrice() << "\t" << p.getSugar() << "\t" << p.getSugarPrice()  << "\t" << p.getRice() << "\t" << p.getRicePrice() << endl;
	   cout << "Ceres    " << c.getIron() << "\t" << c.getIronPrice() << "\t" << c.getSugar() << "\t" << c.getSugarPrice()  << "\t" << c.getRice() << "\t" << c.getRicePrice() << endl;
	   //cout << "Jupiter" << j.getIron() << "\t" << j.getIronPrice() << "\t" << j.getSugar() << "\t" << j.getSugarPrice()  << "\t" << j.getRice() << "\t" << j.getRicePrice() << endl;
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