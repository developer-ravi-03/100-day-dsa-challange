// two sum
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> findDuplets(vector<int> &arr, int tar)
{
  vector<pair<int, int>> ans;
  int n = arr.size();
  // cout << n;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == tar)
      {
        ans.push_back({i, j});
      }
    }
  }
  return ans;
}
int main()
{
  // vector<int> arr = {1, 3, 2, 4, 3, 4, 1, 6};
  vector<int> arr = {1, 3, 2, 4, 3, 4, 1, 6};
  vector<pair<int, int>> ans = findDuplets(arr, 7);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "(" << ans[i].first << ", " << ans[i].second << ")" << endl;
  }

  return 0;
}