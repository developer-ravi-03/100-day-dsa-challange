// Subarray Sums Divisible by K
// Leetcode : 974
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    int n = nums.size();
    int count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];

      int rem = sum % k;
      // handle negative
      if (rem < 0)
      {
        rem = rem + k;
      }

      int freq = mp[rem];

      count += freq;
      mp[rem]++;
    }
    return count;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {4, 5, 0, -2, -3, 1};
  int k = 5;
  cout << sol.subarraysDivByK(nums, k) << endl;
  return 0;
}