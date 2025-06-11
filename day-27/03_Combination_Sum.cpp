// Combination Sum
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
// TC: O(2^n) where n is the number of elements in the array.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<vector<int>> s;
void getAllCombinations(vector<int> &arr, int idx, int tar,
                        vector<vector<int>> &ans, vector<int> &combine)
{

  if (idx == arr.size() || tar < 0)
    return;

  if (tar == 0)
  {
    if (s.find(combine) == s.end())
    {
      ans.push_back(combine);
      s.insert(combine);
    }
    return;
  }

  combine.push_back(arr[idx]);

  // single
  getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combine);
  // multiple
  getAllCombinations(arr, idx, tar - arr[idx], ans, combine);
  combine.pop_back();

  // exclusion
  getAllCombinations(arr, idx + 1, tar, ans, combine);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
  vector<vector<int>> ans;
  vector<int> combine;

  getAllCombinations(arr, 0, target, ans, combine);

  return ans;
}
int main()
{
  vector<int> arr = {2, 3, 5};
  int target = 8;
  vector<vector<int>> ans = combinationSum(arr, target);
  for (auto &v : ans)
  {
    for (auto &i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}