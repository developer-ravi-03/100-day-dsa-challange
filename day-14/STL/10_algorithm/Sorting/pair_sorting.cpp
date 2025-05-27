#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparitor(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second < p2.second)
    return true;             // sorting on second parameter
  if (p1.second > p2.second) // if second parameter is same
    return false;

  if (p1.first < p2.first) // than sort on first parameter
    return true;
  else
    return false;
}

int main()
{

  vector<pair<int, int>> vecp = {{20, 32}, {111, 2}, {4, 1}, {67, 2}};
  sort(vecp.begin(), vecp.end(), comparitor);
  for (auto val : vecp)
  {
    cout << val.first << " " << val.second << endl;
  }
  return 0;
}