#include <iostream>
using namespace std;
class Teacher
{
private:
  double salary;

public:
  string name;
  string dept;
  string subject;
  // parameterized constructor
  Teacher(string name, string dept, string subject, double salary)
  {
    cout << "Parameterized constructor called" << endl;
    // Using 'this' pointer to refer to the current object's members
    // left side of the assignment is the current object's member
    // right side of the assignment is the parameter passed to the constructor
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
  }

  void getInfo()
  {
    cout << "Name: " << name << endl;
    cout << "Department: " << dept << endl;
    cout << "Subject: " << subject << endl;
    cout << "Salary: " << salary << endl;
  }
};
int main()
{
  // parameterized constructor called
  Teacher t1("John", "CSE", "C++", 50000);
  t1.getInfo();
  return 0;
}