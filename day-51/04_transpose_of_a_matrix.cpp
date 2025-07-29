#include <iostream>
using namespace std;
int main()
{
  int arr[3][2] = {{1, 20}, {4, 9}, {6, 7}};
  int transpose[2][3];

  //  print transpose
  for (int i = 0; i < 2; i++) // col
  {
    for (int j = 0; j < 3; j++) // row
    {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }

  //  store transpose
  for (int i = 0; i < 2; i++) // col
  {
    for (int j = 0; j < 3; j++) // row
    {
      transpose[i][j] = arr[j][i];
    }
  }

  //  print transpose
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << transpose[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}