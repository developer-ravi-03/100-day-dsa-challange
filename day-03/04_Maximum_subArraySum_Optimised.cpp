// brute force approach
#include <iostream>
#include <climits>
using namespace std;
int main()
{
  // int arr[] = {1, 2, 3, 4, 5};
  // int n = 5;
  int arr[] = {3, 4, -5, -1};
  int n = 4;
  int maxSum = INT_MIN;
  int currSum = 0;
  for (int i = 0; i < n; i++)
  {
    currSum += arr[i];
    cout << "current sum :" << currSum << endl;
    maxSum = max(currSum, maxSum);
    cout << "Max sum after every iteration :" << maxSum << endl;
    if (currSum < 0)
    {
      currSum = 0;
    }
  }
  cout << "Total number of subarrays: " << maxSum << endl;
  return 0;
}
