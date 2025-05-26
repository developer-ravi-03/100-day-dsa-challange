// Leetcode -75
// Sort Array with 0s,1s,2s
// Brute Force Approach
// TC - O(NLogn)
// SC - O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void SortArray(vector<int> &A)
{
  sort(A.begin(), A.end());
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