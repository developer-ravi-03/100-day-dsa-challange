// brute force approach
#include <iostream>
#include <climits>
using namespace std;
int main()
{
  // int arr[] = {1, 2, 3, 4, 5};
  // int n = 5;
  int arr[] = {3, -4, 5, 4, -1, 7, -8};
  int n = 7;
  int maxSum = INT_MIN;
  for (int st = 0; st < n; st++)
  {
    int CurrSum = 0;
    for (int end = st; end < n; end++)
    {
      CurrSum += arr[end];
      // cout << "current sum : " << CurrSum << endl;
      maxSum = max(CurrSum, maxSum);
      // cout << "before after number of subarrays: " << maxSum << endl;
    }
    // cout << "after number of subarrays: " << maxSum << endl;
  }
  cout << "Total number of subarrays: " << maxSum << endl;
  return 0;
}
