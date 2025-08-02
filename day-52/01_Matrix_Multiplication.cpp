#include <iostream>
using namespace std;
int main()
{
  int arr1[2][3] = {1, 2, 3, 4, 5, 6};
  int m = 2, n = 3;
  int arr2[3][4] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 4, 2, 8};
  int p = 3, q = 4;

  cout << "First Matrix: " << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr1[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Second Matrix: " << endl;
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << arr2[i][j] << " ";
    }
    cout << endl;
  }

  if (n == p)
  {
    int res[m][q];

    // assign zero to all
    // for (int i = 0; i < m; i++)
    // {
    //   for (int j = 0; j < q; j++)
    //   {
    //     res[i][j] = 0;
    //   }
    // }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < q; j++)
      {
        res[i][j] = 0;
        for (int k = 0; k < n; k++)
        {
          res[i][j] += arr1[i][k] * arr2[k][j];
        }
      }
    }

    cout << "Result Matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < q; j++)
      {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}