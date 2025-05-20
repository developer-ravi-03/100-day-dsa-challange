// Linear Search
// TC- O(n)
#include <iostream>
using namespace std;

void LinearSearch(int arr[], int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      cout << endl;
      cout << "Index of element : " << target << " is:" << i;
      break;
    }
    cout << endl;
    cout << "Loop run times:" << i << endl;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {2, 3, 4, 9, 5, 8, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 4;

  cout << "Array : ";
  printArray(arr, size);
  LinearSearch(arr, size, target);

  return 0;
}