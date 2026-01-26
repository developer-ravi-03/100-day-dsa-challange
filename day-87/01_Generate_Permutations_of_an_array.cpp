// Generate Permutations of an array
// GFG : Problem of the day
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void solve(int idx, vector<vector<int>> &ans, vector<int> &arr)
  {
    // Base case: all positions fixed
    if (idx == arr.size())
    {
      ans.push_back(arr);
      return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
      swap(arr[idx], arr[i]);   // choose
      solve(idx + 1, ans, arr); // explore
      swap(arr[idx], arr[i]);   // un-choose (backtrack)
    }
  }

  vector<vector<int>> permuteDist(vector<int> &arr)
  {
    // code here
    vector<vector<int>> ans;
    solve(0, ans, arr);
    return ans;
  }
};
int main()
{
  Solution solution;
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> result = solution.permuteDist(arr);

  for (const auto &perm : result)
  {
    for (int num : perm)
    {
      cout << num << " ";
    }
    cout << "\n";
  }
  return 0;
}