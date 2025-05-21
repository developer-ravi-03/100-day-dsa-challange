// Binary Search
// it works on sorted array
// TC- O(log n)
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int target, int st, int end)
{
  if (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (target < arr[mid])
      return BinarySearch(arr, target, st, mid - 1);

    else if (target > arr[mid])
      return BinarySearch(arr, target, mid + 1, end);

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
  int target = 4, st = 0, end = size - 1;

  cout << "Array : ";
  printArray(arr, size);
  int index = BinarySearch(arr, target, st, end);
  cout << endl;
  cout << "element found at index:" << index;

  return 0;
}