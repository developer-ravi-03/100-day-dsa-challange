// Number of Centered Subarrays
// Leetcode:3804
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
  int centeredSubarrays(vector<int> &nums)
  {

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      unordered_set<int> st;
      int sum = 0;
      for (int j = i; j < nums.size(); j++)
      {
        sum += nums[j];
        st.insert(nums[j]);
        if (st.find(sum) != st.end())
        {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 7, 1, 4};
  cout << sol.centeredSubarrays(nums) << endl;
  return 0;
}