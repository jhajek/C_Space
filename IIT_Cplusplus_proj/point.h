#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <windows.h>

using namespace std;

class point : public space
{
   private:
	  short coord;
   public:
	   point();
	   //void setP(short p);
	   short getP();
	   ~point();
};

point::point()
{

	srand(time(0)); 
   coord = (((rand() % 10) + 1) * 10);      // Initialize random number generator.

}

short point::getP()
{
	return coord;
}

point::~point()
{
	cout << "Here's the point..." << endl;
}