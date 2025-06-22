#include <iostream>
#include <list>
using namespace std;

class Stack
{
  list<int> ll;

public:
  // Push_back
  void push(int val)
  { // O(1)
    ll.push_front(val);
  }

  // pop_back
  void pop()
  { // O(1)
    ll.pop_front();
  }

  // TOP
  int top()
  { // O(1)
    return ll.front();
  }

  // empty
  bool empty()
  { // O(1)
    return ll.size() == 0;
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}