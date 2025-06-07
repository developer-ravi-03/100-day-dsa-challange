// Brute Force Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
  int n = nums.size();
  int count = 0;

  for (int i = 0; i < n; i++)
  { // starting point
    int sum = 0;
    for (int j = i; j < n; j++)
    { // ending point
      sum += nums[j];
      if (sum == k)
        count++;
    }
  }
  return count;
}
int main()
{
  vector<int> nums = {9, 4, 20, 3, 10, 5};
  int k = 33;
  int ans = subarraySum(nums, k);
  cout << "Ans : " << ans << endl;
  return 0;
}