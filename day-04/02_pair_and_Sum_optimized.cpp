// brute force approach
#include <iostream>
#include <vector>
using namespace std;
vector<int> pairAndSum(vector<int> arr, int target)
{
  vector<int> ans;
  int n = arr.size();
  int i = 0, j = n - 1;

  while (i < j)
  {
    int pairsum = arr[i] + arr[j];
    if (pairsum > target)
    {
      j--;
    }
    else if (pairsum < target)
    {
      i++;
    }
    else
    {
      ans.push_back(i);
      ans.push_back(j);
      return ans;
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {2, 7, 11, 15};
  int target = 18;

  vector<int> ans = pairAndSum(arr, target);
  cout << "the index of ans:";
  cout << ans[0] << "," << ans[1] << endl;
  return 0;
}