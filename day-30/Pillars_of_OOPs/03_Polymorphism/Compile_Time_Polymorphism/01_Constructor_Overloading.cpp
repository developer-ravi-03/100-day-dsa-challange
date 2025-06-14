#include <iostream>
using namespace std;
class Person
{
public:
  string name;
  Person()
  {
    cout << "Non-parameterized constructor called" << endl;
  }
  Person(string n)
  {
    name = n;
    cout << "Parameterized constructor called with name: " << name << endl;
  }
};
int main()
{
  Person p1;          // Calls non-parameterized constructor
  Person p2("Alice"); // Calls parameterized constructor with name "Alice"
  return 0;
}