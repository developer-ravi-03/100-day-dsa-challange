#include <iostream>
using namespace std;
class A
{
public:
  int x;
  void incX()
  {
    x = x + 1;
  }
};
int main()
{
  A obj;
  A obj2;
  obj.x = 100;                             // Initialize x
  obj2.x = 200;                            // Initialize x for obj2
  cout << "Value of x: " << obj.x << endl; // Output will be 1
  obj.incX();
  cout << "Value of x: " << obj2.x << endl; // Output will be 1

  return 0;
}