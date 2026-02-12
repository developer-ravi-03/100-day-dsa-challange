// Check if any two intervals intersect in a given set
// GFG
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  bool isIntersect(vector<vector<int>> intervals)
  {
    // Code Here
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
           return a[0] < b[0];
         });

    int end1 = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
      int start2 = intervals[i][0];
      int end2 = intervals[i][1];
      if (end1 >= start2)
      {
        return true;
      }
      else
      {

        end1 = end2;
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> intervals = {{1, 5}, {7, 9}};
  cout << (sol.isIntersect(intervals) ? "true" : "false") << endl;

  intervals = {{1, 5}, {3, 7}};
  cout << (sol.isIntersect(intervals) ? "true" : "false") << endl;
  return 0;
}