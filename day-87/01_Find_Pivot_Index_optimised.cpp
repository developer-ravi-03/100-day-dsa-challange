//  Find Pivot Index
// Leetcode : 724
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int pivotIndex(vector<int> &arr)
  {
    int n = arr.size();
    int left = 0;
    int right = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += arr[i];
    }

    // ✅ check pivot at index 0
    if (sum - arr[0] == 0)
      return 0;

    for (int i = 1; i < n; i++)
    {
      left += arr[i - 1];
      right = sum - left - arr[i];
      if (left == right)
      {
        return i;
      }
    }

    return -1;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << sol.pivotIndex(nums) << endl;
  return 0;
}