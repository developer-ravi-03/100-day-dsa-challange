// Leetcode-238
// Product of Array Except Self
// brute force approach
// TC- O(nSquare)
#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int> arr)
{
  int n = arr.size();
  vector<int> ans(n, 1);
  for (int i = 0; i < n; i++)
  {
    int product = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        product = product * arr[j];
      }
      ans[i] = product;
    }
  }
  return ans;
}
int main()
{
  vector<int> arr = {1, 2, 3, 4};
  vector<int> ans = product(arr);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}