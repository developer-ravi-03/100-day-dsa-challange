// TC : O(n)
// SC : O(2*n)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class MinStack
{
public:
  stack<pair<int, int>> s; // val,minVal
  MinStack()
  {
  }

  void push(int val)
  {
    if (s.empty())
    {
      s.push({val, val});
    }
    else
    {
      int minVal = min(val, s.top().second);
      s.push({val, minVal});
    }
  }

  void pop()
  {
    s.pop();
  }

  int top()
  {
    return s.top().first;
  }

  int getMin()
  {
    return s.top().second;
  }
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