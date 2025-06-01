#include <iostream>
using namespace std;
// int linearSearch(int arr[4][3], int rows, int cols, int key)
// {
//   for (int i = 0; i < rows; i++)
//   {
//     for (int j = 0; j < cols; j++)
//     {
//       if (arr[i][j] == key)
//       {
//         cout << i << " " << j;
//       }
//     }
//   }
// }

// bool linearSearch(int arr[][3], int rows, int cols, int key)
// {
//   for (int i = 0; i < rows; i++)
//   {
//     for (int j = 0; j < cols; j++)
//     {
//       if (arr[i][j] == key)
//       {
//         return true;
//       }
//     }
//   }
//   return false;
// }

pair<int, int> linearSearch(int arr[4][3], int rows, int cols, int key)
{

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (arr[i][j] == key)
      {
        return {i, j};
      }
    }
  }
  return {-1, -1};
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
  int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  int rows = 4;
  int cols = 3;
  int key = 8;
  printArray(matrix, rows, cols);
  pair<int, int> index = linearSearch(matrix, rows, cols, key);
  cout << index.first << "," << index.second;
  return 0;
}