#include <iostream>
#include <queue>
using namespace std;
int main()
{
  // by default greater
  priority_queue<int> q;
  q.push(5);
  q.push(3);
  q.push(10);
  q.push(4);
  while (!q.empty())
  {
    cout << q.top() << " ";
    q.pop();
  }

  // by compare based greater
  cout << endl;
  priority_queue<int, vector<int>, greater<int>> q1;
  q1.push(5);
  q1.push(3);
  q1.push(10);
  q1.push(4);
  while (!q1.empty())
  {
    cout << q1.top() << " ";
    q1.pop();
  }
  return 0;
}