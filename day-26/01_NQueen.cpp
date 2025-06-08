// Leetcode: 51
// N Queen Problem
// TC : O(n!)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{ // O(n)
  // horizontal
  for (int j = 0; j < n; j++)
  {
    if (board[row][j] == 'Q')
      return false;
  }

  // vertical
  for (int i = 0; i < n; i++)
  {
    if (board[i][col] == 'Q')
      return false;
  }

  // left Diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j] == 'Q')
      return false;
  }

  // right Diagonal
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
  {
    if (board[i][j] == 'Q')
      return false;
  }

  return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
  if (row == n)
  {
    ans.push_back({board});
    return;
  }

  for (int j = 0; j < n; j++)
  {
    if (isSafe(board, row, j, n))
    {
      board[row][j] = 'Q';
      nQueen(board, row + 1, n, ans);
      board[row][j] = '.';
    }
  }
}
vector<vector<string>> solveNQueens(int n)
{
  vector<string> board(n, string(n, '.')); // initialise with -> ....
  vector<vector<string>> ans;
  nQueen(board, 0, n, ans);
  return ans;
}
int main()
{
  int n = 4;
  vector<vector<string>> ans = solveNQueens(n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "Solution " << i + 1 << ":\n";
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << endl;
    }
    cout << endl;
  }

  return 0;
}