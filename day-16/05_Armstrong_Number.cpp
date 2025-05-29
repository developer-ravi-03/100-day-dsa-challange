#include <iostream>
using namespace std;
string armstrongNumber(int n)
{
  int sum = 0;
  int temp = n;
  while (n != 0)
  {
    int digit = n % 10;
    sum = (digit * digit * digit) + sum;
    // cout << sum << endl;
    n /= 10;
  }

  if (sum == temp)
  {
    return "Armstrong Number";
  }
  else
  {
    return "Not Armstrong Number";
  }
}
int main()
{
  int n = 153;
  string ans = armstrongNumber(n);
  cout << ans << endl;
  return 0;
}