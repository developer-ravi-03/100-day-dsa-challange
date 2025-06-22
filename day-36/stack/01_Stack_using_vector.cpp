#include <iostream>
#include <vector>
using namespace std;

class Stack
{
  vector<int> v;

public:
  // Push_back
  void push(int val)
  { // O(1)
    v.push_back(val);
  }

  // pop_back
  void pop()
  { // O(1)
    v.pop_back();
  }

  // TOP
  int top()
  { // O(1)
    return v[v.size() - 1];
  }

  // empty
  bool empty()
  { // O(1)
    return v.size() == 0;
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