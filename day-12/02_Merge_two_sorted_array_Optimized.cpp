// Leetcode -88
// Two Pointer Approach
// TC - O(m + n)
// SC - O(1)
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &A, int m, vector<int> &B, int n)
{
  int idx = m + n - 1;
  int i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0)
  {
    if (A[i] >= B[j])
    {
      A[idx] = A[i];
      i--, idx--;
    }
    else
    {
      A[idx] = B[j];
      idx--;
      j--;
    }
  }

  while (j >= 0)
  {
    A[idx--] = B[j--];
  }

  cout << "Merged Array: ";
  for (int x = 0; x < m + n; x++)
  {
    cout << A[x] << " ";
  }
}
int main()
{
  vector<int> A = {1, 2, 3, 0, 0, 0};
  int m = 3, n = 3;
  vector<int> B = {2, 5, 6};

  merge(A, m, B, n);

  cout << "" << endl;
  return 0;
}