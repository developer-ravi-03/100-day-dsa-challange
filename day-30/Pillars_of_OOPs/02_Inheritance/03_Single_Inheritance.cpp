#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  int age;
};

class Student : public Person
{
public:
  int rollNo;

  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << rollNo << endl;
  }
};

int main()
{
  Student s1;
  s1.name = "Ravi Kumar";
  s1.age = 25;
  s1.rollNo = 101;
  s1.display();
  return 0;
}