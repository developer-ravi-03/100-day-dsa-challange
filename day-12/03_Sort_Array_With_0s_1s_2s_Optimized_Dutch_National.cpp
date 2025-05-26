// Leetcode -75
// Sort Array with 0s,1s,2s
// Optimized Approach --> Dutch national flag algorithm
// 3 pointer approach
// TC - O(n)
// SC - O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void SortArray(vector<int> &A)
{
  int n = A.size();
  int mid = 0, high = n - 1, low = 0;
  while (mid <= high)
  {
    if (A[mid] == 0)
    {
      // swap(A[low], A[mid]);
      // low++;
      // mid++;

      // alternate
      swap(A[low++], A[mid++]);
    }
    else if (A[mid] == 1)
    {
      mid++;
    }
    else
    {
      // swap(A[high], A[mid]);
      // high--;

      // alternate
      swap(A[high--], A[mid]);
    }
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