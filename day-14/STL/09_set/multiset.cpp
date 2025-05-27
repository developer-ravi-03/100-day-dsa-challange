#include <iostream>
#include <set>
using namespace std;
int main()
{
  multiset<int> s;

  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);

  s.insert(3);
  s.insert(4);
  s.insert(5);

  cout << "lower_bound : " << *(s.lower_bound(5)) << endl;
  cout << "upper_bound : " << *(s.upper_bound(3)) << endl;
  for (auto p : s)
  {
    cout << p << " ";
  }

  return 0;
}