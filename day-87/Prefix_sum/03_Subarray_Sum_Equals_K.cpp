// Subarray Sum Equals K
// Leetcode:560
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      int freq = mp[sum - k];
      count += freq;
      mp[sum]++;
    }
    return count;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 1};
  int k = 2;
  int result = sol.subarraySum(nums, k);
  cout << "Number of subarrays with sum " << k << ": " << result << endl;
  return 0;
}