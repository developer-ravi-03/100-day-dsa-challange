// DSA sheet
// Min And Max Element
// TC: O(n)
// SC: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  pair<int, int> getMinMax(vector<int> arr)
  {
    // code here
    pair<int, int> minMax;
    int n = arr.size();

    // if one element
    if (n == 1)
    {
      minMax.first = arr[0];
      minMax.second = arr[0];
      return minMax;
    }

    // if more than two element than initialise
    if (arr[0] > arr[1])
    {
      minMax.first = arr[1];
      minMax.second = arr[0];
    }
    else
    {
      minMax.first = arr[0];
      minMax.second = arr[1];
    }

    for (int i = 2; i < n; i++)
    {
      if (arr[i] > minMax.second)
        minMax.second = arr[i];

      else if (arr[i] < minMax.first)
        minMax.first = arr[i];
    }
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