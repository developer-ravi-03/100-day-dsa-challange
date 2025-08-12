#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int jump(vector<int> &nums)
{
  int totalJump = 0;
  int dest = nums.size() - 1;
  int coverage = 0, lastjumpIdx = 0;
  for (int i = 0; i <= dest; i++)
  {
    coverage = max(coverage, i + nums[i]);

    if (lastjumpIdx == i)
    {
      lastjumpIdx = coverage;
      totalJump++;

      if (coverage >= dest)
      {
        return totalJump;
      }
    }
  }

  return totalJump;
}
int main()
{
  vector<int> nums = {2, 4, 1, 2, 3, 1, 1, 2};
  int ans = jump(nums);
  cout << "ans : " << ans;
  return 0;
}