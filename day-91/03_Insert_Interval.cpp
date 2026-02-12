// Insert Interval
// Leetcode : 57
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval)
  {
    vector<vector<int>> res;
    bool inserted = false;

    for (int i = 0; i < intervals.size(); i++)
    {
      if (!inserted && intervals[i][0] >= newInterval[0])
      {
        res.push_back(newInterval);
        inserted = true;
      }
      res.push_back(intervals[i]);
    }
    if (!inserted)
    {
      res.push_back(newInterval);
      inserted = true;
    }

    vector<vector<int>> ans;
    int start1 = res[0][0];
    int end1 = res[0][1];
    for (int i = 1; i < res.size(); i++)
    {
      int start2 = res[i][0];
      int end2 = res[i][1];
      if (end1 >= start2)
      {
        end1 = max(end1, end2);
      }
      else
      {
        ans.push_back({start1, end1});
        start1 = res[i][0];
        end1 = res[i][1];
      }
    }
    ans.push_back({start1, end1});

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 9}};
  vector<int> newInterval = {2, 5};
  vector<vector<int>> result = sol.insert(intervals, newInterval);

  for (auto &interval : result)
  {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl;
  return 0;
}