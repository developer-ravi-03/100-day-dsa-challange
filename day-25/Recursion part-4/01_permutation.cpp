// Leetcode: 46
// Permutation
// TC : O(n! * n)
// SC : O(n!)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{

  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }

  for (int i = idx; i < nums.size(); i++)
  {
    swap(nums[idx], nums[i]); // idx place => ith element choice
    getPerms(nums, idx + 1, ans);

    swap(nums[idx], nums[i]); // backtracking
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  getPerms(nums, 0, ans);
  return ans;
}
int main()
{
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans = permute(arr);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "]";
  }
  return 0;
}