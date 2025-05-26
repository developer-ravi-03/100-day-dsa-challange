// Leetcode -75
// Sort Array with 0s,1s,2s
// Optimized Approach
// TC - O(n)
// SC - O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void SortArray(vector<int> &A)
{
  // Step 1 - count all 0,1,2 element
  int count0 = 0, count1 = 0, count2 = 0;
  int n = A.size();
  for (int i = 0; i < n; i++)
  {
    if (A[i] == 0)
    {
      count0++;
    }
    else if (A[i] == 1)
    {
      count1++;
    }
    else
    {
      count2++;
    }
  }

  // Step 2 - arrange all elemnt
  int idx = 0;
  for (int i = 0; i < count0; i++)
  {
    A[idx++] = 0;
  }

  for (int i = 0; i < count1; i++)
  {
    A[idx++] = 1;
  }

  for (int i = 0; i < count2; i++)
  {
    A[idx++] = 2;
  }
}
int main()
{
  vector<int> A = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
  SortArray(A);
  cout << "Sorted Array: ";
  for (int x = 0; x < A.size(); x++)
  {
    cout << A[x] << " ";
  }
  return 0;
}