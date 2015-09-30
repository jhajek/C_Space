#include <iostream>
using namespace std;

class Student
{
private:
   char name[50];
   int stunum;
public:
   Student(char *n,int sn=12345);
   void setstunum(int sn);
   int getstunum();
   void Student::setname(char *n);
   char *Student::getname();
   ~Student();
};
 
Student::Student(char *n,int sn)
{
   strcpy(name,n);
   stunum = sn;
}
 
void Student::setstunum(int sn)
{
   stunum = sn;
}
 
int Student::getstunum()
{
   return stunum;
}
 
void Student::setname(char *n)
{
   strcpy(name,n);
}
 
char *Student::getname()
{
   return name;
}
 
Student::~Student()
{
   cout << "Object has been destroyed" << endl;
}