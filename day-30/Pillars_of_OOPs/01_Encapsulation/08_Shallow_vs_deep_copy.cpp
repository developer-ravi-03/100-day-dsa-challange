#include <iostream>
using namespace std;
class Student
{
public:
  string name;
  double *cgpaptr; // pointer created to hold CGPA

  Student(string name, double cgpa)
  {
    this->name = name;
    cgpaptr = new double; // dynamically allocate memory for cgpa
    *cgpaptr = cgpa;      // assign value to the allocated memory
  }

  // custom copy constructor
  Student(Student &orgObj)
  {
    cout << "I am custom copy constructor" << endl;
    this->name = orgObj.name;
    this->cgpaptr = orgObj.cgpaptr;
  }

  void getInfo()
  {
    cout << "Name: " << name << endl;
    cout << "CGPA: " << *cgpaptr << endl;
  }
};
int main()
{
  Student s1("Rahul Kumar", 8.9);

  // Shallow Copy
  Student s2(s1);
  s1.getInfo();
  *(s2.cgpaptr) = 9.5; // modifying CGPA of s2
  cout << "After modifying CGPA of s2:" << endl;
  s1.getInfo(); // s1's CGPA also changes due to shallow copy
  return 0;
}