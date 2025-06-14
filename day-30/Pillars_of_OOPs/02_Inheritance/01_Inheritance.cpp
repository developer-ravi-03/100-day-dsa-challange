#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  int age;
  Person()
  {
    cout << "Parent constructor..." << endl;
  }
  ~Person()
  {
    cout << "Parent destructor..." << endl;
  }
};

class Student : public Person
{
public:
  int rollNo;
  Student() { cout << "Child constructor..." << endl; }
  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << rollNo << endl;
  }
  ~Student()
  {
    cout << "Child destructor..." << endl;
  }
};

int main()
{
  Student s1;
  s1.name = "Ravi Kumar";
  s1.age = 20;
  s1.rollNo = 101;
  s1.display();
  return 0;
}