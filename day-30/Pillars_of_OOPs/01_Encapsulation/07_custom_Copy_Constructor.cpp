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
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
  }

  Teacher(Teacher &orgObj)
  {
    cout << "I am custom copy constructor" << endl;
    this->name = orgObj.name;
    this->dept = orgObj.dept;
    this->subject = orgObj.subject;
    this->salary = orgObj.salary;
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

  Teacher t2(t1); // custom: Copy constructor - invoked
  t2.getInfo();
  return 0;
}