// Quick Sort Algorithm Implementation in C++
//  TC: O(n log n) on average, O(n^2) in the worst case
//  SC: O(log n) for the recursive stack space
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
  int pivot = arr[end];
  int idx = st - 1;
  for (int j = st; j < end; j++)
  {
    if (arr[j] <= pivot)
    {
      idx++;
      swap(arr[idx], arr[j]);
    }
  }

  idx++;
  swap(arr[idx], arr[end]); // placing pivot at correct position
  return idx;               // returning pivot index
}

void quickSort(vector<int> &arr, int st, int end)
{
  if (st < end)
  {
    int pivIdx = partition(arr, st, end);
    quickSort(arr, st, pivIdx - 1);  // left half
    quickSort(arr, pivIdx + 1, end); // right half
  }
}
int main()
{
  vector<int> arr = {12, 31, 35, 8, 32, 17};
  int start = 0;
  int end = arr.size() - 1;
  quickSort(arr, start, end);
  cout << "Sorted array: ";
  for (int val : arr)
  {
    cout << val << " ";
  }
  return 0;
}