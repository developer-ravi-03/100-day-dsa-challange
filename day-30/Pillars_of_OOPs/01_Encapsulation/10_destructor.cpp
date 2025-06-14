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

  // destructor
  ~Student()
  {
    cout << "I delete everything\n";
    delete cgpaptr; // free the dynamically allocated memory
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
  s1.getInfo();
  return 0;
}