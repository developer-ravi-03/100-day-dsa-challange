#include <iostream>
using namespace std;
int main()
{
  int arr1[3][3] = {{1, 20, 3}, {4, 9, 6}, {6, 7, 8}};
  int arr2[3][3] = {{1, 20, 3}, {4, 9, 6}, {6, 7, 8}};
  int res[3][3];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      res[i][j] = arr1[i][j] + arr2[i][j];
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}