// Leetcode:78
// Subset
// TC: O(2^n * n)
#include <iostream>
#include <vector>
using namespace std;
void getAllSubset(vector<int> &arr, vector<int> &ans, int i,
                  vector<vector<int>> &allSubsets)
{
  if (i == arr.size())
  {
    allSubsets.push_back({ans});
    return;
  }

  // include
  ans.push_back(arr[i]);
  getAllSubset(arr, ans, i + 1, allSubsets);

  ans.pop_back(); // Backtrack

  // exclude
  getAllSubset(arr, ans, i + 1, allSubsets);
}
vector<vector<int>> subsets(vector<int> &arr)
{
  vector<vector<int>> allSubsets;
  vector<int> ans;

  getAllSubset(arr, ans, 0, allSubsets);
  return allSubsets;
}
int main()
{
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans = subsets(arr);

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