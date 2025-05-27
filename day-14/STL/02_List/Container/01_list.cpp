#include <iostream>
#include <list>
using namespace std;
int main()
{
  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_front(3);
  l.push_front(5);

  cout << endl;
  for (int val : l)
  {
    cout << val << " ";
  }

  l.pop_back();
  l.pop_front();
  cout << endl;
  for (int val : l)
  {
    cout << val << " ";
  }

  l.emplace_back(8);
  l.emplace_front(99);
  cout << endl;
  for (int val : l)
  {
    cout << val << " ";
  }
  return 0;
}