// Leetcode-238
// Product of Array Except Self
// Optimal approach
// TC- O(n)
// SC- O(1)
#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int> arr)
{
  int n = arr.size();
  vector<int> ans(n, 1);
  // prefix => ans
  for (int i = 1; i < n; i++)
  {
    ans[i] = ans[i - 1] * arr[i - 1];
  }

  // suffix
  int suffix = 1;
  for (int i = n - 2; i >= 0; i--)
  {
    suffix *= arr[i + 1];
    ans[i] *= suffix;
  }
  return ans;
}
int main()
{
  vector<int> arr = {1, 2, 3, 4};
  vector<int> ans = product(arr);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}