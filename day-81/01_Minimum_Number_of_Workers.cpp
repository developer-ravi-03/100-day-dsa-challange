// Minimum Number of Workers
// GFG : Problem of the day

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  int minMen(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    vector<int> maxReach(n, -1);

    for (int i = 0; i < n; i++)
    {
      int st = max(0, i - arr[i]);
      int end = min(n - 1, i + arr[i]);
      maxReach[st] = max(maxReach[st], end);
    }

    int workers = 0;
    int currIdx = -1;
    int mxIdx = -1;
    int i = 0;

    while (i < n)
    {
      mxIdx = max(mxIdx, maxReach[i]);

      if (currIdx < i)
      {
        if (mxIdx < i)
        {
          return -1;
        }
        else
        {
          currIdx = mxIdx;
          workers++;
        }
      }
      i++;
    }

    return workers;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 3, 2, 0, 4};
  cout << sol.minMen(arr) << endl;
  return 0;
}