// Implement Queue using Stacks
// Leetcode: 232
#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
public:
  stack<int> s1;
  stack<int> s2;
  MyQueue() {}

  void push(int x)
  {
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
      s1.push(s2.top());
      s2.pop();
    }
  }

  int pop()
  {
    if (s1.empty())
      return -1;
    int front = s1.top();
    s1.pop();
    return front;
  }

  int peek()
  {
    return s1.top();
  }

  bool empty()
  {
    return s1.empty();
  }
};
int main()
{
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << q.peek() << endl;  // Output: 1
  cout << q.pop() << endl;   // Output: 1
  cout << q.pop() << endl;   // Output: 2
  cout << q.empty() << endl; // Output: 0
  cout << q.pop() << endl;   // Output: 3
  cout << q.empty() << endl; // Output: 1
  return 0;
}