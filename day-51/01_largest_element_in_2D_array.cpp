#include <iostream>
using namespace std;
int main()
{
  int arr[3][3] = {{1, 20, 3}, {4, 9, 6}, {6, 7, 8}};
  int max = -1;
  int second = -1;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (max < arr[i][j])
      {
        max = arr[i][j];
      }
      if (max != arr[i][j] && second < arr[i][j])
      {
        second = arr[i][j];
      }
    }
  }

    cout << "greater element : " << max << endl;
  cout << "second greater element : " << second;
  return 0;
}