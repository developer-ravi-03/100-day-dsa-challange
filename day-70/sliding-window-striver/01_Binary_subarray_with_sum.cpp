// Leetcode-930
// Binary Subarray with Sum

// Exact sum in binary array = atMost(goal) − atMost(goal−1)
// find all subarray with at mist gial and less then goal than we are able to find exact goal
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int atMost(vector<int> &nums, int goal)
  {
    if (goal < 0)
      return 0;
    int ans = 0;
    int sum = 0;
    int low = 0;
    for (int high = 0; high < nums.size(); high++)
    {
      sum += nums[high];
      while (sum > goal)
      {
        sum -= nums[low];
        low++;
      }
      ans += (high - low + 1);
    }
    return ans;
  }
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    return atMost(nums, goal) - atMost(nums, goal - 1);
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  cout << sol.numSubarraysWithSum(nums, goal) << endl;
  return 0;
}