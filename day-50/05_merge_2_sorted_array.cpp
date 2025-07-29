#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int idx = m + n - 1;
  int i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0)
  {
    if (nums1[i] >= nums2[j])
    {
      nums1[idx] = nums1[i];
      idx--;
      i--;
    }
    else
    {
      nums1[idx] = nums2[j];
      idx--;
      j--;
    }
  }
  while (j >= 0)
  {
    nums1[idx--] = nums2[j--];
  }
}

int main()
{
  vector<int> num1 = {1, 4, 5, 8, 0, 0, 0, 0, 0};
  vector<int> num2 = {2, 3, 6, 7, 10};
  int m = 4, n = 5;
  merge(num1, m, num2, n);
  for (int i = 0; i < num1.size(); i++)
  {
    cout << num1[i] << " ";
  }

  return 0;
}