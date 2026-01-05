// Count Number of Nice Subarrays
// Leetcode : 1248
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int countNum(vector<int> &nums, int k)
  {
    if (k < 0)
      return 0;
    int subarr = 0;
    int ct = 0;
    int low = 0;
    for (int high = 0; high < nums.size(); high++)
    {
      if (nums[high] % 2 == 1)
        ct++;
      while (ct > k)
      {
        if (nums[low] % 2 == 1)
          ct--;
        low++;
      }
      subarr += (high - low + 1);
    }
    return subarr;
  }
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return countNum(nums, k) - countNum(nums, k - 1);
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << sol.numberOfSubarrays(nums, k) << endl;
  return 0;
}