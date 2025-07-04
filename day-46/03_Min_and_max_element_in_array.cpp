// DSA sheet
// Min And Max Element
// TC: O(N)
// SC: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
  int minarr(vector<int> arr, int n)
  {
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] < min)
        min = arr[i];
    }

    return min;
  }

  int maxarr(vector<int> arr, int n)
  {
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > max)
        max = arr[i];
    }

    return max;
  }
  pair<int, int> getMinMax(vector<int> arr)
  {
    // code here
    pair<int, int> minMax;
    int n = arr.size();

    minMax.first = minarr(arr, n);
    minMax.second = maxarr(arr, n);

    return minMax;
  }
};

int main()
{
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
  Solution sol;
  pair<int, int> result = sol.getMinMax(arr);
  cout << "Min: " << result.first << ", Max: " << result.second << endl;
  return 0;
}