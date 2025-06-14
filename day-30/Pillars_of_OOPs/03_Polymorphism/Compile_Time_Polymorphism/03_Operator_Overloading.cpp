#include <iostream>
using namespace std;
class Print
{
public:
  int y = 10;
  int x = y;
  string str = "Hello";
  string s = str;
  void show()
  {
    cout << "Value of x: " << x << endl;
    cout << "String: " << s << endl;
  }
};
int main()
{
  Print p;
  p.show(); // Calls show() method

  return 0;
}