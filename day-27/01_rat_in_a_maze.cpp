// Rat in a Maze Problem
// Given a maze of size n x n, where each cell can either be blocked (0) or open (1),
// find all possible paths from the top-left corner (0, 0) to the bottom-right corner (n-1, n-1).
// The rat can only move in four directions: up, down, left, and right.
// The rat cannot move through blocked cells (0) and cannot visit the same cell more than once.
// The output should be a list of strings, where each string represents a path using the characters 'D', 'U', 'L', and 'R' for down, up, left, and right respectively.
// The paths should be in lexicographical order.
// TC : O(4^(n^2))
// SC: O(n^2) for visited array
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// this is helper function
void helper(vector<vector<int>> &maze, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis)
{
  int n = maze.size();
  // base case -first check valid cell or not
  if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || vis[r][c] == true)
  {
    return;
  }

  if (r == n - 1 && c == n - 1)
  {
    ans.push_back(path);
    return;
  }

  // mark the cell as visited
  vis[r][c] = true;

  // down
  helper(maze, r + 1, c, path + "D", ans, vis);

  // up
  helper(maze, r - 1, c, path + "U", ans, vis);

  // left
  helper(maze, r, c - 1, path + "L", ans, vis);

  // right
  helper(maze, r, c + 1, path + "R", ans, vis);

  // backtrack - unmark the cell
  vis[r][c] = false;
}

// complete this function
vector<string> findPath(vector<vector<int>> &maze)
{
  int n = maze.size();
  vector<string> ans;
  string path = "";
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  helper(maze, 0, 0, path, ans, vis);
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