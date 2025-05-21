// Leetcode - 33
//  Search in Rotated sorted array
// O (log n)
#include <iostream>
using namespace std;
int SearchInArray(int arr[], int size, int target)
{
  int st = 0, end = size - 1;
  while (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }

    if (arr[st] <= arr[mid]) // Left Sorted
    {
      if (arr[st] <= target && target <= arr[mid])
        end = mid - 1;
      else
        st = mid + 1;
    }
    else
    {
      if (arr[mid] <= target && target <= arr[end])

        st = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
}
int main()
{
  int arr[] = {3, 4, 5, 6, 7, 0, 1, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 0;
  int index = SearchInArray(arr, size, target);
  cout << "Index of element : " << index << endl;
  return 0;
}