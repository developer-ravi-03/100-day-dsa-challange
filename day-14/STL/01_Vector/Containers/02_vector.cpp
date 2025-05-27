#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> vec = {
      3,
      2,
      4,
      1,
      5,
      6,
      8,
      9,
  };

  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  // delete specific position
  vec.erase(vec.begin());
  vec.erase(vec.begin() + 2);
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  // delete any range
  vec.erase(vec.begin() + 2, vec.begin() + 4);
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  // insert
  vec.insert(vec.begin() + 2, 38);
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  // delete all element
  vec.clear();
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  cout << "is empty: " << vec.empty() << endl;

  return 0;
}