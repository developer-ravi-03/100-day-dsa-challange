#include <iostream>
using namespace std;
int main()
{
  int arr1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int m = 3, n = 3;

  cout << "First Matrix: " << endl;
  for (int j = 0; j < n; j++)
  {

    if (j % 2 == 0)
    {
      for (int i = 0; i < m; i++)
      {
        cout << arr1[i][j] << " ";
      }
    }
    else
    {
      for (int i = m - 1; i >= 0; i--)
      {
        cout << arr1[i][j] << " ";
      }
    }

    // cout << endl;
  }
  return 0;
}