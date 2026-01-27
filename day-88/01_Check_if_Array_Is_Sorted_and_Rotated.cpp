// 1752. Check if Array Is Sorted and Rotated
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size();
    int ct = 0;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] < nums[i - 1])
      {
        ct++;
      }
      else
      {
        continue;
      }
    }
    if (nums[n - 1] > nums[0])
      ct++;

    return ct <= 1;
  }
};
int main()
{
  Solution sol;
  vector<int> nums1 = {3, 4, 5, 1, 2};
  cout << "Test 1: " << sol.check(nums1) << endl;

  vector<int> nums2 = {2, 1};
  cout << "Test 2: " << sol.check(nums2) << endl;

  vector<int> nums3 = {1, 2, 3};
  cout << "Test 3: " << sol.check(nums3) << endl;
  return 0;
}