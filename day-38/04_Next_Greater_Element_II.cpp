// Leetcode : 503
// Next Greater Element II
// TC : O(n)
// SC : O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (s.size() > 0 && nums[s.top()] <= nums[i % n])
      {
        s.pop();
      }
      ans[i % n] = s.empty() ? -1 : nums[s.top()];
      s.push(i % n); // push valid idx
    }
    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 3};
  Solution sol;
  vector<int> res = sol.nextGreaterElements(nums);
  for (int x : res)
    cout << x << " ";
  cout << endl;
  return 0;
}