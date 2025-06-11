// TC: O(4^(n^2))
// SC: O(1) for the visited array

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// this is helper function
void helper(vector<vector<int>> &maze, int r, int c, string path, vector<string> &ans)
{
  int n = maze.size();
  // base case -first check valid cell or not
  if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || maze[r][c] == -1)
  {
    return;
  }

  if (r == n - 1 && c == n - 1)
  {
    ans.push_back(path);
    return;
  }

  // mark the cell as visited
  maze[r][c] = -1;

  // down
  helper(maze, r + 1, c, path + "D", ans);

  // up
  helper(maze, r - 1, c, path + "U", ans);

  // left
  helper(maze, r, c - 1, path + "L", ans);

  // right
  helper(maze, r, c + 1, path + "R", ans);

  // backtrack - unmark the cell
  maze[r][c] = 1;
  // Note: We set the cell back to 1 instead of using a visited array.
}

// complete this function
vector<string> findPath(vector<vector<int>> &maze)
{
  int n = maze.size();
  vector<string> ans;
  string path = "";

  helper(maze, 0, 0, path, ans);
  return ans;
}

int main()
{
  vector<vector<int>> maze = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};

  vector<string> ans = findPath(maze);
  for (string path : ans)
  {
    cout << path << endl;
  }

  return 0;
}