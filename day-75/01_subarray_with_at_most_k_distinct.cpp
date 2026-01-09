// Subarrays with at most K distinct elements
// GFG Problem of the day
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int countAtMostK(vector<int> &arr, int k)
  {
    // code here
    if (k < 0)
      return 0;
    int subArr = 0;
    int low = 0;
    unordered_map<int, int> mp;
    for (int high = 0; high < arr.size(); high++)
    {
      mp[arr[high]]++;
      while (mp.size() > k)
      {
        mp[arr[low]]--;
        if (mp[arr[low]] == 0)
        {
          mp.erase(arr[low]);
        }
        low++;
      }
      subArr += (high - low + 1);
    }
    return subArr;
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 1, 2, 3};
  int k = 2;
  cout << "Subarrays with at most " << k << " distinct elements: " << sol.countAtMostK(arr, k) << endl;
  return 0;
}