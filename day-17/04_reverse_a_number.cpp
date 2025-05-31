// Leetcode: 07
// Reverse Integer
#include <iostream>
#include <climits>
using namespace std;

int revNum(int a)
{
  int rev = 0;
  while (a != 0)
  {
    int digit = a % 10;
    if (rev > INT_MAX / 10 || rev < INT_MIN / 10) // for checking out of range or not
      return 0;
    rev = (rev * 10) + digit;
    // cout << digit << endl;
    a /= 10;
  }
  return rev;
}

int main()
{
  int a = 4357;
  cout << "Reversed Number : : " << revNum(a);

  return 0;
}