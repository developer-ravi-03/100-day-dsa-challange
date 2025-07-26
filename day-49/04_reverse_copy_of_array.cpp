
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  vector<int> v = {1, 3, 2, 4, 3, 4, 1, 6};
  vector<int> v2(v.size());
  int n = v.size();
  for (int i = 0; i < v.size(); i++)
  {
    v2[i] = v[n - i - 1];
  }

  for (int i = 0; i < n; i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}