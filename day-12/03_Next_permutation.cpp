// leetcode - 33
// Next Permutation problem
// Optimized Approach
// TC - O(n)
// SC- O(1)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void nextPermutation(vector<int> &A)
{
  int pivot = -1;
  int n = A.size();
  // Step 1 to find pivot
  for (int i = n - 2; i >= 0; i--)
  {
    if (A[i] < A[i + 1])
    {
      pivot = i;
      break;
    }
  }

  if (pivot == -1)
  {
    reverse(A.begin(), A.end()); // in place changes
    return;
  }

  // 2nd step for next larger element
  for (int i = n - 1; i > pivot; i--)
  {
    if (A[i] > A[pivot])
    {
      swap(A[i], A[pivot]);
      break;
    }
  }

  // 3rd Atep: reverse(pivot+1 to n-1)
  // alternate
  // reverse(A.begin() + pivot + 1, A.end());

  int i = pivot + 1;
  int j = n - 1;
  while (i <= j)
  {
    swap(A[i], A[j]);
    i++;
    j--;
  }
}
int main()
{
  vector<int> A = {3, 2, 1};
  nextPermutation(A);
  cout << "Next Permutation Array: ";
  for (int x = 0; x < A.size(); x++)
  {
    cout << A[x] << " ";
  }
  return 0;
}