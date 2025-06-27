// Leetcode : 239
// Sliding Maximum Window
// TC : O(n)
// SC : O(n)
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    deque<int> dq;
    vector<int> res;
    int n = nums.size();

    // first window
    for (int i = 0; i < k; i++)
    {
      while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        dq.pop_back();

      dq.push_back(i);
    }

    // Sliding window maximum for other window
    for (int i = k; i < n; i++)
    {
      res.push_back(nums[dq.front()]); // ans

      // Remove not part of curr window
      while (dq.size() > 0 && dq.front() <= i - k)
        dq.pop_front();

      // remove smaller value form end
      while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        dq.pop_back();

      dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    return res;
  }
};
int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution sol;
  vector<int> result = sol.maxSlidingWindow(nums, k);
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}