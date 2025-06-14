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
int main()
{
  Student s1;
  s1.name = "John Doe";
  s1.rollno = 123;
  cout << "Student Name: " << s1.name << endl;
  cout << "Roll No: " << s1.rollno << endl;
  Teacher t1;
  t1.name = "Jane Smith";
  t1.subject = "Mathematics";
  t1.salary = 60000;
  cout << "Teacher Name: " << t1.name << endl;
  cout << "Subject: " << t1.subject << endl;
  cout << "Salary: " << t1.salary << endl;
  // Hierarchical inheritance allows both Student and Teacher to inherit from Person

  return 0;
}