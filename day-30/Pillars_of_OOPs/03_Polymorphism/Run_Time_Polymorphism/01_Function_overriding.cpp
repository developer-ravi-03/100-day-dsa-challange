#include <iostream>
using namespace std;
class Parent
{
public:
  void getInfo()
  {
    cout << "Parent class getInfo function called" << endl;
  }
};
class Child : public Parent
{
public:
  void getInfo()
  {
    cout << "Child class getInfo function called" << endl;
  }
};
int main()
{
  Parent p;
  p.getInfo(); // Calls Parent class getInfo function
  Child c;
  c.getInfo(); // Calls Child class getInfo function
  return 0;
}