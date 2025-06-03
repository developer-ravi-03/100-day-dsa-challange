// Leetcode :- 240
// Search in 2D matrix II
// TC :- O(m+n)
#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int tar)
{
  int m = mat.size(), n = mat[0].size();
  int r = 0, c = n - 1;
  while (c >= 0 && r < m)
  {
    if (tar == mat[r][c])
      return true;
    if (tar < mat[r][c])
      c--;
    if (tar > mat[r][c])
      r++;
  }
  return false;
}

int main()
{
  vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  int target = 5;
  cout << searchMatrix(mat, target);
  return 0;
}