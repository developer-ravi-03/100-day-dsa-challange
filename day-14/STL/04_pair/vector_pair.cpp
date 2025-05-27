#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<pair<int, int>> p = {{1, 2}, {2, 3}, {3, 4}};

  for (pair<int, int> val : p)
  {
    cout << val.first << " " << val.second << endl;
  }

  p.push_back({4, 5});  // it only insert
  p.emplace_back(5, 6); // inplace object create

  // alternate
  cout << "with auto keyword" << endl;
  for (auto val : p)
  {
    cout << val.first << " " << val.second << endl;
  }

  return 0;
}