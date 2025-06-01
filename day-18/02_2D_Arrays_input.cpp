#include <iostream>
using namespace std;
void inputArray(int arr[4][3], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> arr[i][j];
    }
  }
}

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
  int matrix[4][3];
  int rows = 4;
  int cols = 3;

  cout << "Enter Number of array: ";
  inputArray(matrix, rows, cols);
  cout << "Matrix is :" << endl;
  printArray(matrix, rows, cols);
  return 0;
}