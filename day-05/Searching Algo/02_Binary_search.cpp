// Binary Search
// it works on sorted array
// TC- O(log n)
// SC- O(log n)
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target)
{
  int st = 0, end = size - 1;
  while (st <= end)
  {

    int mid = st + (end - st) / 2;
    if (arr[mid] < target)
    {
      st = mid + 1;
    }
    else if (arr[mid] > target)
      end = mid - 1;
    else
      return mid;
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
  int arr[] = {1, 2, 3, 4, 5, 6, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 4;

  cout << "Array : ";
  printArray(arr, size);
  int index = BinarySearch(arr, size, target);
  cout << endl;
  cout << "element found at index:" << index;

  return 0;
}