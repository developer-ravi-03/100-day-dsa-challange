#include <iostream>
using namespace std;

class Person
{
public:
  string name;
};

class Teacher : public Person
{
public:
  string subject;
  int salary;
};
class Student : public Person
{
public:
  int rollno;
};

class TA : public Student, public Teacher
{
};
int main()
{

  TA t2;
  t2.Teacher::name = "Ravi Kumar";
  t2.rollno = 101;
  t2.subject = "Computer Science";
  t2.salary = 50000;
  cout << "TA Name: " << t2.Teacher::name << endl;
  cout << "Roll No: " << t2.rollno << endl;
  cout << "Subject: " << t2.subject << endl;
  cout << "Salary: " << t2.salary << endl;

  return 0;
}