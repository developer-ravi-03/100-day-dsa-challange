// Leetcode -88
// Normal Approach
// TC - O(m + n)
// SC - O(m + n)

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> A, int m, vector<int> B, int n)
{
  vector<int> C(m + n);
  int i = 0, j = 0, k = 0;
  while (i < m && j < n)
  {
    if (A[i] <= B[j])
    {
      C[k++] = A[i++];
      // C[k] = A[i];
      // i++, k++;
    }
    else
    {
      C[k] = B[j];
      j++, k++;
    }
  }

  while (i < m)
  {
    C[k] = A[i];
    i++, k++;
  }

  while (j < n)
  {
    C[k] = B[j];
    j++, k++;
  }

  cout << "Merged Array C: ";
  for (int x = 0; x < m + n; x++)
  {
    cout << C[x] << " ";
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