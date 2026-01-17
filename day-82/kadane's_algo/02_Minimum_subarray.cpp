// Smallest sum contiguous subarray
// GFG
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int smallestSumSubarray(vector<int> &a)
  {
    // Code here
    int minSum = a[0];
    int ans = a[0];

    for (int i = 1; i < a.size(); i++)
    {
      int v1 = minSum + a[i];
      int v2 = a[i];
      minSum = min(v1, v2);
      ans = min(ans, minSum);
    }
    return ans;
  }
};

int main()
{
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution sol;
  cout << sol.smallestSumSubarray(nums) << endl;
  return 0;
}