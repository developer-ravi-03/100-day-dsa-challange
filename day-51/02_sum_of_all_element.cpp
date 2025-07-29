#include <iostream>
using namespace std;
int main()
{
  int arr[3][3] = {{1, 20, 3}, {4, 9, 6}, {6, 7, 8}};
  int sum = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sum += arr[i][j];
    }
  }

  cout << "sum : " << sum << endl;
  return 0;
}