// Find the Duplicate Number
// slow fast pointer
// Leetcode: 287
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int slow = nums[0], fast = nums[0];

    // detect cycle
    do
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // find number
    slow = nums[0];
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
int main()
{
  Solution obj;
  vector<int> nums = {1, 3, 4, 2, 2};
  cout << "Duplicate number: " << obj.findDuplicate(nums) << endl;
  return 0;
}