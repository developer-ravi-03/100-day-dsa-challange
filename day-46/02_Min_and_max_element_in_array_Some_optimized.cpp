// DSA sheet
// Min And Max Element
// TC: O(N logn)
// SC: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  pair<int, int> getMinMax(vector<int> arr)
  {
    // code here
    pair<int, int> minMax;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    minMax.first = arr[0];
    minMax.second = arr[n - 1];

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