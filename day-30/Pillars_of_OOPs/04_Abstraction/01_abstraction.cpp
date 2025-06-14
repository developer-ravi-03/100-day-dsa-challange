#include <iostream>
using namespace std;
// Abstract class
class Shape
{ // automatic abstract class
public:
  // Pure virtual function
  virtual void draw() = 0; // This makes Shape an abstract class
};

class Circle : public Shape
{
public:
  // Implementation of the pure virtual function
  void draw() override
  {
    cout << "Drawing a Circle" << endl;
  }
};
int main()
{
  Circle c1;
  c1.draw();
  return 0;
}