// Count Subarray with k odds
// GFG : problem of the day
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int countAtMost(vector<int> &arr, int k)
  {
    if (k < 0)
      return 0;

    int subArr = 0;
    int low = 0;
    int oddCount = 0;

    for (int high = 0; high < arr.size(); high++)
    {
      if (arr[high] % 2 == 1)
      {
        oddCount++;
      }

      while (oddCount > k)
      {
        if (arr[low] % 2 == 1)
        {
          oddCount--;
        }
        low++;
      }

      subArr += (high - low + 1);
    }

    return subArr;
  }

  int countSubarrays(vector<int> &arr, int k)
  {
    return countAtMost(arr, k) - countAtMost(arr, k - 1);
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 2;
  cout << sol.countSubarrays(arr, k) << endl;
  return 0;
}