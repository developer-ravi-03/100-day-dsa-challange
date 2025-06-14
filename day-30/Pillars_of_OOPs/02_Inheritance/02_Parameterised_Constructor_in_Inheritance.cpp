#include <iostream>
using namespace std;

class Person
{
public:
  string name;
  int age;
  Person(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
};

class Student : public Person
{
public:
  int rollNo;

  // here call parent class constructor
  //  using member initializer list
  Student(string name, int age, int rollNo) : Person(name, age)
  {
    this->rollNo = rollNo;
  }
  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << rollNo << endl;
  }
};

int main()
{
  Student s1("Ravi Kumar", 20, 101);

  s1.display();
  return 0;
}