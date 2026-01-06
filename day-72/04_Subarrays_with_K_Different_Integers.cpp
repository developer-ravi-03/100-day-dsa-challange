// Subarrays with K Different Integers
// Leetcode : 922
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int count(vector<int> &nums, int k)
  {
    if (k < 0)
      return 0;
    unordered_map<int, int> mp;
    int ctSubArr = 0;
    int low = 0;
    for (int high = 0; high < nums.size(); high++)
    {
      mp[nums[high]]++;
      while (mp.size() > k)
      {
        mp[nums[low]]--;
        if (mp[nums[low]] == 0)
        {
          mp.erase(nums[low]);
        }
        low++;
      }
      ctSubArr += (high - low + 1);
    }
    return ctSubArr;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    return count(nums, k) - count(nums, k - 1);
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  cout << sol.subarraysWithKDistinct(nums, k) << endl;
  return 0;
}