// Maximum Subarray
// Leetcode:53
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int bestEnd = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      int v1 = bestEnd + nums[i];
      int v2 = nums[i];
      bestEnd = max(v1, v2);
      ans = max(ans, bestEnd);
    }
    return ans;
  }
};
int main()
{
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution sol;
  cout << sol.maxSubArray(nums) << endl;
  return 0;
}