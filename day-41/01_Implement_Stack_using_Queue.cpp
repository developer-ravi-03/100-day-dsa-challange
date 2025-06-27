// Leetcode : 225
#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
public:
  queue<int> q1;
  queue<int> q2;
  MyStack() {}

  void push(int x)
  { // O(n)
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }

    q1.push(x);

    while (!q2.empty())
    {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop()
  {
    int ans = q1.front();
    q1.pop();
    return ans;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};
int main()
{
  MyStack st;
  st.push(10);
  st.push(20);
  st.push(30);

  cout << "Top: " << st.top() << endl;                         // Should print 30
  cout << "Pop: " << st.pop() << endl;                         // Should print 30
  cout << "Top: " << st.top() << endl;                         // Should print 20
  cout << "Pop: " << st.pop() << endl;                         // Should print 20
  cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl; // Should print No
  cout << "Pop: " << st.pop() << endl;                         // Should print 10
  cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl; // Should print Yes
  return 0;
}