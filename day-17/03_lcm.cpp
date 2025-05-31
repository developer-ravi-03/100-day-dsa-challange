#include <iostream>
using namespace std;

int gcdRec(int a, int b)
{
  if (b == 0)
    return a;
  return gcdRec(b, a % b);
}
int lcm(int a, int b)
{
  int gcd = gcdRec(a, b);
  return (a * b) / gcd;
}
int main()
{
  int a = 12, b = 60;
  cout << "lcm : " << lcm(a, b);

  return 0;
}