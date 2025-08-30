#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rows, cols;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          rows.push_back(i);
          cols.push_back(j);
        }
      }
    }

    // update rows zero
    for (int r : rows)
    {
      for (int j = 0; j < n; j++)
      {
        matrix[r][j] = 0;
      }
    }

    // update cols zero
    for (int c : cols)
    {
      for (int i = 0; i < m; i++)
      {
        matrix[i][c] = 0;
      }
    }
  }
};
int main()
{
  vector<vector<int>> matrix = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};

  Solution sol;
  sol.setZeroes(matrix);

  for (const auto &row : matrix)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
