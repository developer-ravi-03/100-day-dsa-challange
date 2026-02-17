// Next Greater Element II
// Leetcode : 503
// Method : 2 -> without using 2n extra space
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
    st.push(nums[n - 1]);
    for (int i = 2 * n - 2; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums[i % n])
        st.pop();

      if (!st.empty())
        ans[i % n] = st.top();

      st.push(nums[i % n]);
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