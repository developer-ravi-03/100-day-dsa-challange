#include <iostream>
using namespace std;
void function()
{
  static int count = 0; // Static variable
  cout << "Count: " << count << endl;
  count++;
}
int main()
{
  function();
  function();
  function();
  function();

  return 0;
}