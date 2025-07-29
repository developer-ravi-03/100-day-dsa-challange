#include <iostream>
using namespace std;
int main()
{
  int arr[4][4] = {
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
  };

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // for (int i = 0; i < 4; i++)
  // {
  //   for (int j = i; j < 4; j++)
  //   {
  //     if (i == j)
  //     {
  //       arr[i][j] = arr[i][j];
  //     }
  //     else
  //     {
  //       swap(arr[j][i], arr[i][j]);
  //     }
  //   }
  // }

  for (int i = 0; i < 4; i++)
  {
    for (int j = i + 1; j < 4; j++)
    {

      swap(arr[j][i], arr[i][j]);
    }
  }

  for (int i = 0; i < 4; i++) // col
  {
    for (int j = 0; j < 4; j++) // row
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}