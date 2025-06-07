// Leetcode:90
// Subset II
// TC: O(2^n * n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getAllSubsets(vector<int> &nums, vector<int> &ans, int i,
                   vector<vector<int>> &allSubsets)
{
  if (i == nums.size())
  { // best case
    allSubsets.push_back({ans});
    return;
  }

  ans.push_back(nums[i]); // inclusion
  getAllSubsets(nums, ans, i + 1, allSubsets);
  ans.pop_back(); // exclusion
  int idx = i + 1;
  while (idx < nums.size() &&
         nums[idx] == nums[idx - 1]) // skip the duplicate values
    idx++;

  getAllSubsets(nums, ans, idx, allSubsets);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  sort(nums.begin(), nums.end());

  vector<vector<int>> allSubsets;
  vector<int> ans;
  getAllSubsets(nums, ans, 0, allSubsets);
  return allSubsets;
}

int main()
{
  vector<int> arr = {1, 2, 2};
  vector<vector<int>> ans = subsetsWithDup(arr);

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