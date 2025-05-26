// in this we find Minimum time taken to paint
// arr=[40,30,10,20]
// 1. p1=40    p2=60  --> in this case minimum Time taken
// 2. p1=70    p2=30
// 3. p1=80    p2=20
// TC=O(n*log n)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
  int painters = 1, time = 0;
  for (int i = 0; i < n; i++) // O(n)
  {
    if (time + arr[i] <= maxAllowedTime)
    {
      time += arr[i];
    }
    else
    {
      painters++;
      time = arr[i];
    }
  }
  return painters <= m;
}

int minTimeToPaint(vector<int> arr, int n, int m)
{
  int sum = 0, maxval = INT_MIN;
  for (int i = 0; i < n - 1; i++)
  {
    sum += arr[i];
    maxval = max(maxval, arr[i]);
  }
  int st = maxval, end = sum, ans = -1;

  while (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (isPossible(arr, n, m, mid)) // left
    {
      ans = mid;
      end = mid - 1;
    }
    else
    { // right
      st = mid + 1;
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {40, 30, 10, 20};
  int n = 4, m = 2;

  cout << minTimeToPaint(arr, n, m) << endl;
  return 0;
}