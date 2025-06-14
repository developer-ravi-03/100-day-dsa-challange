#include <iostream>
using namespace std;
class Parent
{
public:
  void getInfo()
  {
    cout << "Parent class getInfo function called" << endl;
  }
  virtual void hello()
  {
    cout << "Parent class hello function called" << endl;
  }
};
class Child : public Parent
{
public:
  void getInfo()
  {
    cout << "Child class getInfo function called" << endl;
  }
  void hello()
  {
    cout << "Child class hello function called" << endl;
  }
};
int main()
{
  Parent p;
  p.getInfo(); // Calls Parent class getInfo function
  p.hello();   // Calls Parent class hello function
  Child c;
  c.getInfo(); // Calls Child class getInfo function
  c.hello();   // Calls Child class hello function
  return 0;
}