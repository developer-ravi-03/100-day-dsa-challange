// Merge Intervals
// Leetcode : 56
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (intervals.empty())
      return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] <= end)
      {
        end = max(end, intervals[i][1]);
      }
      else
      {
        ans.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }
    ans.push_back({start, end});
    return ans;
  }
};
int main()
{
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution sol;
  vector<vector<int>> result = sol.merge(intervals);
  for (auto interval : result)
  {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl;
  return 0;
}