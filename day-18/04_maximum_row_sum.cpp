#include <iostream>
#include <climits>
using namespace std;
void printArray(int arr[4][3], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int getMaxSum(int arr[4][3], int rows, int cols)
{
  int maxRowSum = INT_MIN;

  for (int i = 0; i < rows; i++)
  {
    int rowSumI = 0;
    for (int j = 0; j < cols; j++)
    {
      rowSumI += arr[i][j];
    }
    maxRowSum = max(maxRowSum, rowSumI);
  }
  return maxRowSum;
}

int main()
{
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
  int rows = 3;
  int cols = 3;

  printArray(matrix, rows, cols);
  cout << getMaxSum(matrix, rows, cols);
  return 0;
}