// Maximum Absolute Sum of Any Subarray
// Leetcode:1749
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxAbsoluteSum(vector<int> &nums)
  {
    int maxSum = nums[0];
    int MinSum = nums[0];
    int maxAns = nums[0];
    int minAns = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      maxSum = max(maxSum + nums[i], nums[i]);
      maxAns = max(maxAns, maxSum);

      MinSum = min(MinSum + nums[i], nums[i]);
      minAns = min(minAns, MinSum);
    }
    return max(abs(minAns), maxAns);
  }
};
int main()
{
  vector<int> nums = {1, -3, 2, 3, -2};
  Solution sol;
  cout << "Maximum Absolute Sum: " << sol.maxAbsoluteSum(nums) << endl;
  return 0;
}