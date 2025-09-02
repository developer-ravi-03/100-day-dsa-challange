// Leetcode - 289
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void gameOfLife(vector<vector<int>> &board)
  {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> copy = board;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int cell = copy[i][j];
        int count = 0;
        if (j > 0 && copy[i][j - 1] == 1)
        {
          count++;
        }
        if (j < m - 1 && copy[i][j + 1] == 1)
        {
          count++;
        }
        if (i > 0 && copy[i - 1][j] == 1)
        {
          count++;
        }
        if (i < n - 1 && copy[i + 1][j] == 1)
        {
          count++;
        }
        if (i > 0 && j > 0 && copy[i - 1][j - 1] == 1)
        {
          count++;
        }
        if (i > 0 && j < m - 1 && copy[i - 1][j + 1] == 1)
        {
          count++;
        }
        if (i < n - 1 && j > 0 && copy[i + 1][j - 1] == 1)
        {
          count++;
        }
        if (i < n - 1 && j < m - 1 && copy[i + 1][j + 1] == 1)
        {
          count++;
        }

        if (cell == 1 && count < 2)
        {
          board[i][j] = 0;
        }

        if (cell == 1 && (count == 2 || count == 3))
        {
          continue;
        }

        if (cell == 1 && count > 3)
        {
          board[i][j] = 0;
        }

        if (cell == 0 && count == 3)
        {
          board[i][j] = 1;
        }
      }
    }
  }
};
int main()
{
  vector<vector<int>> board = {
      {0, 1, 0},
      {0, 0, 1},
      {1, 1, 1},
      {0, 0, 0}};

  Solution sol;
  sol.gameOfLife(board);

  for (const auto &row : board)
  {
    for (int cell : row)
    {
      cout << cell << " ";
    }
    cout << endl;
  }
  return 0;
}