#include <iostream>
using namespace std;
class Teacher
{
private:
  int salary;

public:
  string name;
  string dept;
  string subject;

  void changeDept(string newDept)
  {
    dept = newDept;
  }

  // setter function to set salary
  void setSalary(double sal)
  {
    salary = sal;
  }

  // getter function to get salary
  int getSalary()
  {
    return salary;
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

  // Setting salary using setter function
  t1.setSalary(50000);
  // Getting salary using getter function
  cout << "Salary: " << t1.getSalary() << endl;
  // Changing department using member function
  t1.changeDept("IT");
  cout << "Updated Department: " << t1.dept << endl;
  return 0;
}