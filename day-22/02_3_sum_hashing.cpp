// Leetcode : 15
// 3 Sum
// better hashing approach
// TC: O(n*n*log(uniqueTriplets))
// SC : O(uniqueTriplets+n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
  int n = nums.size();

  set<vector<int>> uniqueTriplet; // set<uniqueTriplet>

  for (int i = 0; i < n; i++)
  {
    int tar = -nums[i];
    set<int> s;
    for (int j = i + 1; j < n; j++)
    {
      int third = tar - nums[j];

      if (s.find(third) != s.end())
      {
        vector<int> trip = {nums[i], nums[j], third};
        sort(trip.begin(), trip.end());
        uniqueTriplet.insert(trip);
      }
      s.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());
  return ans;
}
int main()
{
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = threeSum(nums);
  cout << "{";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "{";
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << ",";
    }
    cout << "}";
  }
  cout << "}";
  return 0;
}