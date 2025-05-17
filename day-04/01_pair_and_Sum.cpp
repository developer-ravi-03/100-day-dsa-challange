// brute force approach
#include <iostream>
#include <vector>
using namespace std;
vector<int> pairAndSum(vector<int> arr, int target)
{
  vector<int> ans;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        // here push index
        ans.push_back(i);
        ans.push_back(j);

        // here push the value of index
        // ans.push_back(arr[i]);
        // ans.push_back(arr[j]);
        return ans;
      }
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {2, 7, 11, 15};
  int target = 9;

  vector<int> ans = pairAndSum(arr, target);
  cout << "the index of ans:";
  cout << ans[0] << "," << ans[1] << endl;
  return 0;
}