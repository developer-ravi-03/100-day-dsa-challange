// Happy Number
// Leetcode : 202
#include <iostream>
using namespace std;
class Solution
{
public:
  int fun(int n)
  {
    int sum = 0;
    while (n != 0)
    {
      int d = n % 10;
      n /= 10;
      // sum+=(d*d);
      sum = sum + (d * d);
      sum = sum + (d * d);
    }
    return sum;
  }
  bool isHappy(int n)
  {
    int slow = n, fast = n;
    while (fast != 1)
    {
      slow = fun(slow);
      fast = fun(fast);
      fast = fun(fast);
      if (slow == fast && slow != 1)
      {
        return false;
      }
    }
    return true;
  }
};
int main()
{
  Solution sol;
  int n = 7;
  if (sol.isHappy(n))
  {
    cout << n << " is a happy number" << endl;
  }
  else
  {
    cout << n << " is not a happy number" << endl;
  }
  return 0;
}