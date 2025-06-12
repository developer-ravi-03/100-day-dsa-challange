// Merge Sort Algorithm Implementation in C++
// TC: O(n log n)
// SC: O(n) for the temporary array used in merging
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
  vector<int> temp;
  int i = st, j = mid + 1;

  // Merging array accordig to value
  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    else
    {
      temp.push_back(arr[j]);
      j++;
    }
  }

  // If any element is left in the left half
  while (i <= mid)
  {
    temp.push_back(arr[i]);
    i++;
  }

  // If any element is left in the right half
  while (j <= end)
  {
    temp.push_back(arr[j]);
    j++;
  }

  for (int idx = 0; idx < temp.size(); idx++)
  {
    arr[st + idx] = temp[idx];
  }
}

void mergeSort(vector<int> &arr, int st, int end)
{
  int mid = st + (end - st) / 2;

  if (st < end)
  {
    mergeSort(arr, st, mid);      // left half
    mergeSort(arr, mid + 1, end); // right half
    merge(arr, st, mid, end);
  }
}
int main()
{
  vector<int> arr = {12, 31, 35, 8, 32, 17};
  int start = 0;
  int end = arr.size() - 1;
  mergeSort(arr, start, end);
  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}