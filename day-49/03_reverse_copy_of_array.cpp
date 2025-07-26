
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  int arr[] = {1, 3, 2, 4, 3, 4, 1, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  int arr2[size];
  for (int i = size - 1; i >= 0; i--)
  {
    arr2[i] = arr[i];
  }

  int i = 0, j = size - 1;
  while (i < j)
  {
    int temp = arr2[i];
    arr2[i] = arr2[j];
    arr2[j] = temp;
    i++;
    j--;
  }

  for (int i = 0; i < size; i++)
  {
    cout << arr2[i] << " ";
  }

  return 0;
}