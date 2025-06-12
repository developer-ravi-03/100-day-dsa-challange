//  Count Inversion in an array using Optimal approach --> using Merge Sort
//  TC : O(n log n)
//  SC : O(n)
#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr, int st, int mid, int end)
{
  vector<int> temp;
  int i = st, j = mid + 1;
  int InvCount = 0;
  // Merging array according to value
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
      // If arr[i] > arr[j], then all elements from arr[i] to arr[mid] are greater than arr[j]
      InvCount += (mid - i + 1);
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

  return InvCount;
}
int mergeSort(vector<int> &arr, int st, int end)
{
  if (st < end)
  {
    int mid = st + (end - st) / 2;
    int leftInvCount = mergeSort(arr, st, mid);
    int rightInvCount = mergeSort(arr, mid + 1, end);
    int InvCount = merge(arr, st, mid, end);
    return leftInvCount + rightInvCount + InvCount;
  }

  return 0;
}

int main()
{
  vector<int> arr = {6, 3, 5, 2, 7};

  int count = mergeSort(arr, 0, arr.size() - 1);
  cout << "Number of inversions: " << count << endl;
  return 0;
}