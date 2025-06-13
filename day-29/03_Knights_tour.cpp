// Leetcode : 2596
//  Problem: Check if a Knight's Tour is Valid
// TC: O(8^n*n) where n is the number of cells in the grid
// SC: O(n*n) for recursion stack
#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expVal)
{
  // Best case
  if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal)
    return false;

  // after moving all cell successfully we need to return true
  // if we reach the last cell
  if (expVal == n * n - 1)
    return true;

  // 8 possible move
  int ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
  int ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
  int ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
  int ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
  int ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
  int ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
  int ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
  int ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

  return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}
bool checkValidGrid(vector<vector<int>> &grid)
{
  int n = grid.size();
  int expVal = 0; // start from zero
  return isValid(grid, 0, 0, n, expVal);
}
int main()
{
  vector<vector<int>> grid = {
      {0, 3, 6},
      {5, 8, 1},
      {2, 7, 4}};
  if (checkValidGrid(grid))
    cout << "Valid Knight's Tour" << endl;
  else
    cout << "Invalid Knight's Tour" << endl;
  return 0;
}