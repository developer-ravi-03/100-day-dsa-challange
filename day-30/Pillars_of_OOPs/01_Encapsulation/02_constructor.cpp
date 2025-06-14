#include <iostream>
using namespace std;
class Teacher
{
private:
  double salary;

public:
  // non parameterized constructor
  Teacher()
  {
    cout << "Default constructor called" << endl;
    dept = "Computer Science";
  }

  string name;
  string dept;
  string subject;

  void setSalary(double sal)
  {
    salary = sal;
  }

  void getSalary()
  {
    cout << "Salary: " << salary << endl;
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
  // non parameterized constructor called
  Teacher t1;
  t1.name = "John";
  t1.subject = "C++";
  t1.dept = "CSE";
  t1.setSalary(50000);
  t1.getInfo();
  return 0;
}