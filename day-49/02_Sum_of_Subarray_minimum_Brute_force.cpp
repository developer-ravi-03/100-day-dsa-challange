// GFG -> Sum of SUbarray Minimum brute force
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  int sumSubMins(vector<int> &arr)
  {
    // code here
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int min = INT_MAX;
        for (int k = i; k <= j; k++)
        {
          cout << arr[k]; // print elements of the subarray
          if (i < j)
            cout << " "; // add space between elements
          if (arr[k] < min)
          {
            min = arr[k];
          }
        }
        cout << endl;
        sum += min;
      }
    }
    cout << "subarray minimum Sum: " << sum << endl;
  }
};

int main()
{
  vector<int> arr = {3, 1, 2, 4};
  Solution sol;
  sol.sumSubMins(arr);
  return 0;
}