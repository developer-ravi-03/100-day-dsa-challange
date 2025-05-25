// Leetcode - 540
//  Single Element In sorted Array
// Optimal approach
// TC - O(log n)
// SC - O(1)
#include <iostream>
#include <vector>
using namespace std;
int SingleElement(vector<int> arr)
{
  int n = arr.size();
  int st = 0, end = n - 1;
  if (n == 1) // if there are only one element in array
    return arr[0];

  while (st <= end)
  {
    int mid = st + (end - st) / 2;

    if (mid == 0 && arr[0] != arr[1]) // if there are only two element in array
      return mid;

    if (mid == (2 * n - 1) && arr[n - 1] != arr[n - 2]) // check last element
      return mid;

    if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
      return mid;

    if (mid % 2 == 0) // if even
    {
      if (arr[mid - 1] == arr[mid])
        end = mid - 1;
      else
        st = mid + 1;
    }
    else // if odd
    {
      if (arr[mid - 1] == arr[mid])
        st = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
}
int main()
{
  vector<int> arr = {0, 0, 1};
  int index = SingleElement(arr);
  cout << "Index of single element : " << index << endl;
  return 0;
}