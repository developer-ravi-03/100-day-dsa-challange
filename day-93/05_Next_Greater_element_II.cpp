// Next Greater Element II
// Leetcode : 503
// Method : 3 -> with entry stack in the begining
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 2; i >= 0; i--)
    {
      st.push(nums[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums[i])
        st.pop();

      if (!st.empty())
        ans[i] = st.top();

      st.push(nums[i]);
    }

    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 1};
  vector<int> result = sol.nextGreaterElements(nums);

  cout << "Next Greater Elements: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}