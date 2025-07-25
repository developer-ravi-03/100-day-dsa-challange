#include <iostream>
#include <climits>
using namespace std;
int main()
{
  int arr[] = {9, 10000, 1, 2, 102, 4, 5, 6};
  // int max = INT_MIN;
  int max = arr[0];
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }
  cout << max;

  return 0;
}