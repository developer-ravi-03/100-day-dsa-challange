// Max Xor Subarray of size K
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  int maxSubarrayXOR(vector<int> &arr, int k)
  {
    // code here
    int n = arr.size();

    int winXOR = 0;
    for (int i = 0; i < k; i++)
    {
      winXOR = winXOR ^ arr[i];
    }

    int maxXOR = winXOR;
    int low = 0, high = k;
    while (high < n)
    {
      low++;
      winXOR = winXOR ^ arr[low - 1];
      high++;
      winXOR = winXOR ^ arr[high - 1];
      maxXOR = max(maxXOR, winXOR);
    }
    return maxXOR;
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {8, 10, 5, 2, 11, 3};
  int k = 2;
  cout << "Maximum XOR in subarray of size " << k << " is: " << sol.maxSubarrayXOR(arr, k) << endl;
  return 0;
}