// leetcode - 50
//  compute x to be power n
#include <iostream>
using namespace std;

double xPowN(double x, int n)
{
  long binform = n;

  // this is for negative power
  if (n < 0)
  {
    x = 1 / x;
    binform = -binform;
  }

  double ans = 1.0;
  while (binform > 0)
  {
    if (binform % 2 == 1)
    {
      ans *= x;
    }
    x *= x;
    binform /= 2;
  }
  return ans;
}

int main()
{
  double x = 3;
  int n = 3;
  double ans = xPowN(x, n);
  cout << "ans = " << ans << endl;
  return 0;
}
