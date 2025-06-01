#include <iostream>
#include <climits>
using namespace std;
void printArray(int arr[4][3], int rows, int cols)
{
  for (int i = 0; i < cols; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

int getMaxSum(int arr[4][3], int rows, int cols)
{
  int maxColSum = INT_MIN;

  // loop over column
  for (int i = 0; i < cols; i++)
  {
    int colSumI = 0;
    for (int j = 0; j < rows; j++)
    {
      colSumI += arr[j][i];
    }
    maxColSum = max(maxColSum, colSumI);
  }
  return maxColSum;
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