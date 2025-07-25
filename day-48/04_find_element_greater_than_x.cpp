#include <iostream>
#include <climits>
using namespace std;
int main()
{
  int arr[] = {9, 10000, 1, 2, 102, 4, 5, 6};
  int x = 100;
  int count = 0;
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    if (arr[i] > x)
      count++;
  }
  cout << count;

  return 0;
}