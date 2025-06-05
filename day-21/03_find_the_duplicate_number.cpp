// Leetcode: 287
// Find Duplicate
// TC: O(n)
// SC: O(1)
#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
  int slow = nums[0], fast = nums[0];

  do
  {
    slow = nums[slow];       //+1
    fast = nums[nums[fast]]; //+2
  } while (slow != fast);

  slow = nums[0];

  while (slow != fast)
  {
    slow = nums[slow]; //+1
    fast = nums[fast]; //+1
  }
  return slow;
}
int main()
{
  vector<int> nums = {3, 1, 3, 4, 2};
  int ans = findDuplicate(nums);
  cout << "duplicate : " << ans << endl;
  return 0;
}