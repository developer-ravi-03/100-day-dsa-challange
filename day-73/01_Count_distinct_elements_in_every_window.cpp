// Count distinct elements in every window
// GFG : problem of the day
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  vector<int> countDistinct(vector<int> &arr, int k)
  {
    // code here
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
      mp[arr[i]]++;
    }
    ans.push_back(mp.size());

    for (int high = k; high < arr.size(); high++)
    {
      mp[arr[high - k]]--;
      if (mp[arr[high - k]] == 0)
        mp.erase(arr[high - k]);
      mp[arr[high]]++;
      ans.push_back(mp.size());
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
  int k = 4;
  vector<int> result = sol.countDistinct(arr, k);
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}