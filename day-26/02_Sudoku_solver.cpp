// Leetcode: 37
// Sudoku solver Problem
// TC : O(9^x)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
{

  // horizontal
  for (int j = 0; j < 9; j++)
  {
    if (board[row][j] == dig)
    {
      return false;
    }
  }

  // vertiical
  for (int i = 0; i < 9; i++)
  {
    if (board[i][col] == dig)
    {
      return false;
    }
  }

  // grid
  int srow = (row / 3) * 3;
  int scol = (col / 3) * 3;
  for (int i = srow; i <= srow + 2; i++)
  {
    for (int j = scol; j <= scol + 2; j++)
    {
      if (board[i][j] == dig)
      {
        return false;
      }
    }
  }

  return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{

  // base case
  if (row == 9)
    return true;

  int nextRow = row;
  int nextCol = col + 1;
  if (nextCol == 9)
  {
    nextRow = row + 1;
    nextCol = 0;
  }

  if (board[row][col] != '.')
  {
    return helper(board, nextRow, nextCol);
  }

  // place the digit
  for (char dig = '1'; dig <= '9'; dig++)
  {
    if (isSafe(board, row, col, dig))
    {
      board[row][col] = dig;
      if (helper(board, nextRow, nextCol))
        return true;
      board[row][col] = '.';
    }
  }

  return false;
}

void solveSudoku(vector<vector<char>> &board) { helper(board, 0, 0); }
int main()
{
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  solveSudoku(board);

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}