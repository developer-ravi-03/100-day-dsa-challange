#include <iostream>
using namespace std;
// Class definition
class Teacher
{
private:
  int salary; // private property
public:
  // properties and attributes
  string name;
  string dept;
  string subject;

  // Member function and methods
  void changeDept(string newDept)
  {
    dept = newDept;
  }
};

class Student
{
public:
  string name;
  int rollNo;
  string dept;

  // Member function to display student information
  void displayInfo()
  {
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Department: " << dept << endl;
  }
};

int main()
{
  Teacher t1; // Object creation
  // Accessing properties and methods
  t1.name = "John";
  t1.dept = "CSE";
  t1.subject = "C++";
  cout << "Name: " << t1.name << endl;
  cout << "Department: " << t1.dept << endl;
  cout << "Subject: " << t1.subject << endl;

  Student s1; // Object creation
  s1.name = "Ravi";
  s1.rollNo = 101;
  s1.dept = "CSE";
  // Displaying student information
  s1.displayInfo();
  return 0;
}