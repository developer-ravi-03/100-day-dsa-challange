//  Maximum Subarray Sum with One Deletion
// Leetcode :1186
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  int maximumSum(vector<int> &arr)
  {
    int noDelete = arr[0];
    int oneDelete = INT_MIN;
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
      int prevNoDelete = noDelete;
      int prevOneDelete = oneDelete;
      noDelete = max(noDelete + arr[i], arr[i]);

      int v2;
      if (prevOneDelete == INT_MIN)
      {
        v2 = arr[i];
      }
      else
      {
        v2 = prevOneDelete + arr[i];
      }

      oneDelete = max(v2, prevNoDelete);
      result = max(result, max(noDelete, oneDelete));
    }
    return result;
  }
};
int main()
{
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution sol;
  cout << sol.maximumSum(arr) << endl;
  return 0;
}
