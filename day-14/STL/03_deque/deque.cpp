#include <iostream>
#include <deque>
using namespace std;
int main()
{
  deque<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_front(3);
  l.push_front(5);

  cout << endl;
  for (int val : l)
  {
    cout << val << " ";
  }

  cout << endl;
  cout << "[1] : " << l[1];
  return 0;
}