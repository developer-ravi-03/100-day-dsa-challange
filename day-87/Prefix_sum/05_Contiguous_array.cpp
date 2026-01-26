// Contiguous Array
// Leetcode : 525
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int findMaxLength(vector<int> &nums)
  {
    int n = nums.size();
    int ans = 0;
    int ones = 0, zeros = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        zeros++;
      }
      else
      {
        ones++;
      }
      int diff = zeros - ones;

      if (diff == 0)
      {
        ans = max(ans, i + 1);
        continue;
      }

      if (mp.find(diff) == mp.end())
      {
        mp[diff] = i;
      }
      else
      {
        int idx = mp[diff];
        int len = i - idx;
        ans = max(ans, len);
      }
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {0, 1, 0};
  cout << sol.findMaxLength(nums) << endl;
  return 0;
}