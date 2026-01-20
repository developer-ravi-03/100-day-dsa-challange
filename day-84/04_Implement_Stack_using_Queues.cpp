// Implement Stack using Queues
// Leetcode: 225
#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
public:
  queue<int> q;
  MyStack() {}

  void push(int x)
  {
    int s = q.size();
    q.push(x);
    for (int i = 1; i <= s; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }

  int pop()
  {
    if (q.size() == 0)
      return -1;
    int top = q.front();
    q.pop();
    return top;
  }

  int top()
  {
    return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};
int main()
{
  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(2);
  obj->push(3);
  cout << "Top: " << obj->top() << endl;
  cout << "Pop: " << obj->pop() << endl;
  cout << "Empty: " << obj->empty() << endl;
  delete obj;
  return 0;
}