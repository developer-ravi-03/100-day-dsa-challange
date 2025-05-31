// Leetcode: 09
// Pallindrome NUmber
#include <iostream>
#include <climits>
using namespace std;

int reverse(int x)
{
  int revNum = 0;
  while (x != 0)
  {
    int dig = x % 10;
    if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
      return 0;
    revNum = (revNum * 10) + dig;
    x /= 10;
  }
  return revNum;
}
bool isPalindrome(int x)
{
  if (x < 0)
    return false;
  int rev = reverse(x);

  if (rev == x)
  {
    return true;
  }
  return false;
}

int main()
{
  int a = 353;
  bool pallindrome = isPalindrome(a);
  if (pallindrome)
  {
    cout << "Pallindrome number";
  }
  else
  {
    cout << "Not Pallindrome number";
  }

  return 0;
}