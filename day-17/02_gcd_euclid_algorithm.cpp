#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  while (a > 0 && b > 0)
  {
    if (a > b)
    {
      a = a % b;
    }
    else
    {
      b = b % a;
    }
  }
  if (a == 0)
  {
    return b;
  }
  return a;
}
int main()
{
  int a = 6, b = 12;
  cout << "gcd : " << gcd(a, b);

  return 0;
}