// Maximum Sum Circular Subarray
// Leetcode :918
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int n = nums.size();
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
      arrSum += nums[i];
    }
    int bestMaxSum = nums[0];
    int bestMinSum = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];
    for (int i = 1; i < n; i++)
    {
      currMax = max(currMax + nums[i], nums[i]);
      bestMaxSum = max(bestMaxSum, currMax);

      currMin = min(currMin + nums[i], nums[i]);
      bestMinSum = min(bestMinSum, currMin);
    }
    if (bestMaxSum < 0)
      return bestMaxSum;

    int circularSum = arrSum - bestMinSum;

    return max(bestMaxSum, circularSum);
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, -2, 3, -2};
  cout << sol.maxSubarraySumCircular(nums) << endl;
  return 0;
}