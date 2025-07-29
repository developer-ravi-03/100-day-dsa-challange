#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = 0, k = 0, j = 0;
  vector<int> ans(m + n);
  while (i <= m && j <= n)
  {
    if (nums1[i] < nums2[j])
    {
      ans[k] = nums1[i];
      i++;
      k++;
    }
    else
    {
      ans[k] = nums2[j];
      j++;
      k++;
    }
  }

  // for remaining element in nums1 array
  while (i < m)
  {
    ans[k] = nums1[i];
    i++;
    k++;
  }

  // for remaining element in nums2 array
  while (j < n)
  {
    ans[k] = nums2[j];
    j++;
    k++;
  }

  return ans;
}

int main()
{
  vector<int> num1 = {1, 4, 5, 8, 12, 34, 56};
  vector<int> num2 = {2, 3, 6, 7, 10, 12};
  int m = 7, n = 6;
  vector<int> ans = merge(num1, m, num2, n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}