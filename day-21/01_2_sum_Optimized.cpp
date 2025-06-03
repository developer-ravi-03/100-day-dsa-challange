// Leetcode :- 01
// 2 Sum
// TC :- O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &arr, int tar)
{
  unordered_map<int, int> m;
  vector<int> ans;
  for (int i = 0; i < arr.size(); i++)
  {
    int first = arr[i];
    int sec = tar - first;

    if (m.find(sec) != m.end())
    {
      ans.push_back(i);
      ans.push_back(m[sec]);
      break;
    }
    m[first] = i;
  }
  return ans;
}
int main()
{
  vector<int> arr = {5, 2, 11, 7, 15};
  int target = 9;
  vector<int> ans = twoSum(arr, target);

  cout << "[" << ans[0] << ", " << ans[1] << "]";

  return 0;
}