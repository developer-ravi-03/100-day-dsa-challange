#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int arr[3][3] = {
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9};

  int m = 3, n = 3;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // transpose
  for (int i = 0; i < m; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      swap(arr[j][i], arr[i][j]);
    }
  }

  cout << " After transpose: " << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  // rotate
  for (int i = 0; i < m; i++)
  {
    int j = 0, k = n - 1;
    while (j < k)
    {
      swap(arr[i][j], arr[i][k]);
      j++;
      k--;
    }
  }

  cout << " After rotation: " << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}