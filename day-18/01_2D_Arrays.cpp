#include <iostream>
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
int main()
{
  int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  int rows = 4;
  int cols = 3;

  matrix[2][2] = 15;
  cout << "matrix[2][2] :" << matrix[2][2] << endl;
  printArray(matrix, rows, cols);
  return 0;
}