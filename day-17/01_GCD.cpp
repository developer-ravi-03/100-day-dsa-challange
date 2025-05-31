#include <iostream>
using namespace std;

void gcd(int a, int b)
{
  int gcd = 1;
  for (int i = 1; i <= min(a, b); i++)
  {
    if (a % i == 0 && b % i == 0)
    {
      gcd = i;
    }
  }
  cout << "GCD : " << gcd;
}
int main()
{
  int a = 6, b = 12;
  gcd(a, b);
  // cout << "" << endl;
  return 0;
}