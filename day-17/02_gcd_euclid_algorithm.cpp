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

int gcdRec(int a, int b)
{
  if (b == 0)
    return a;
  return gcdRec(b, a % b);
}
int main()
{
  int a = 12, b = 60;
  cout << "gcd : " << gcd(a, b) << endl;
  cout << "gcdRec : " << gcdRec(a, b);

  return 0;
}