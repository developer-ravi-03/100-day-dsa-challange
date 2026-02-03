// Longest subarray with given sum K(positives)
// Striver sheet
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int longestSubarray(vector<int> &nums, int k)
  {
    int ans = 0;
    int Sum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      Sum += nums[i];

      if (Sum == k)
      {
        ans = i + 1;
      }

      if (mp.find(Sum - k) != mp.end())
      {
        ans = max(ans, i - mp[Sum - k]);
      }

      if (mp.find(Sum) == mp.end())
        mp[Sum] = i;
    }
    return ans;
  }
};

int main()
{
  vector<int> nums = {15, 2, 4, 8, 9, 5, 10, 23};
  int k = 23;
  Solution sol;
  cout << "Longest subarray length: " << sol.longestSubarray(nums, k) << endl;
  return 0;
}