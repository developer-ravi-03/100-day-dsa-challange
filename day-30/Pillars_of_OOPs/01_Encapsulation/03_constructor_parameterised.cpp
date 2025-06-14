#include <iostream>
using namespace std;
class Teacher
{
private:
  double salary;

public:
    // parameterized constructor
  Teacher(string n, string d, string s, double sal)
  {
    cout << "Parameterized constructor called" << endl;
    name = n;
    dept = d;
    subject = s;
    salary = sal;
  }
  string name;
  string dept;
  string subject;

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