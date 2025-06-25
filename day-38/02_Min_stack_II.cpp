// TC : O(n)
// SC : O(n)
// 2nd Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
  stack<long long int> s;
  long long int minVal;
  MinStack() {}

  void push(int val)
  {
    if (s.empty())
    {
      s.push(val);
      minVal = val;
    }
    else if (val < minVal)
    {
      s.push(2LL * val - minVal);
      minVal = val;
    }
    else
    {
      s.push(val);
    }
  }

  void pop()
  {
    if (s.empty())
      return;
    if (s.top() < minVal)
    {
      minVal = 2LL * minVal - s.top();
    }
    s.pop();
  }

  int top()
  {
    if (s.empty())
      return -1;
    if (s.top() < minVal)
    {
      return minVal;
    }
    else
    {
      return s.top();
    }
  }

  int getMin() { return minVal; }
};

int main()
{
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << "Min: " << minStack.getMin() << endl; // Returns -3
  minStack.pop();
  cout << "Top: " << minStack.top() << endl;    // Returns 0
  cout << "Min: " << minStack.getMin() << endl; // Returns -2
  return 0;
}