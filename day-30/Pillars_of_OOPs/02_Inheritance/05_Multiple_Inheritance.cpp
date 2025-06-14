#include <iostream>
using namespace std;

class Student
{
public:
  int rollNo;
  string name;
};

class Teacher
{
public:
  string subject;
  int salary;
};
class TA : public Student, public Teacher
{
public:
  void display()
  {
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Subject: " << subject << endl;
    cout << "Salary: " << salary << endl;
  }
};
int main()
{
  TA t1;
  t1.name = "Ravi Kumar";
  t1.rollNo = 101;
  t1.subject = "Computer Science";
  t1.salary = 50000;
  t1.display();
  return 0;
}