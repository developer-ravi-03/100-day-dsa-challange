// Aggressive cows problem
// largest minimum distance
// arr=[1,2,8,4,9]
// 1. c1=1    c2=2   c3=4     mindist=1
// 2. c1=2    c2=4   c3=8     mindist=2
// 3. c1=1    c2=4   c3=8     mindist=3
// so the largest minimum distance is 3

// TC=O(n*log n)
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minAllowedDistance) // O(n)
{
  int cows = 1, lastStallPos = arr[0];
  for (int i = 0; i < n; i++)
  {
    if ((arr[i] - lastStallPos) >= minAllowedDistance)
    {
      cows++;
      lastStallPos = arr[i];
    }
    if (cows == c)
    {
      return true;
    }
  }
  return false;
}

int GetDistance(vector<int> &arr, int n, int c)
{
  sort(arr.begin(), arr.end()); // O(Nlogn)

  // st =1, end = maxVal-minVal
  int st = 1, end = arr[n - 1] - arr[0], ans = -1;

  while (st <= end) // O(log(Range) * N)
  {
    int mid = st + (end - st) / 2;
    if (isPossible(arr, n, c, mid)) // right
    {
      ans = mid;
      st = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }

  return ans;
}
int main()
{
  vector<int> arr = {1, 2, 8, 4, 9};
  int n = 5, c = 3;

  cout << GetDistance(arr, n, c) << endl;
  return 0;
}