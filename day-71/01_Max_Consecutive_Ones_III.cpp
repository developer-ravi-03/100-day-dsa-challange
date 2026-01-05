// Max Consecutive Ones III
// Leetcode : 1004
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int ones = 0;
    int low = 0;
    int n = nums.size();
    int ans = 0;
    for (int high = 0; high < n; high++)
    {
      if (nums[high] == 1)
        ones++;
      while ((high - low + 1) - ones > k)
      {
        if (nums[low] == 1)
          ones--;
        low++;
      }
      ans = max(ans, high - low + 1);
    }
    return ans;
  }
};
int main()
{
  Solution solution;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  int result = solution.longestOnes(nums, k);
  cout << "Max consecutive ones: " << result << endl;
  return 0;
}