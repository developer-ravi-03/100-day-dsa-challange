// Leetcode:704
// Binary search with recursion
// TC: O(logN)
// TC: O(logN)
#include <iostream>
#include <vector>
using namespace std;

// helper function
int binSearch(vector<int> &arr, int tar, int st, int end)
{
  if (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (arr[mid] == tar)
      return mid;
    else if (arr[mid] <= tar)
      return binSearch(arr, tar, mid + 1, end);
    else
      return binSearch(arr, tar, st, mid - 1);
  }
  return -1;
}

int search(vector<int> &arr, int tar)
{
  int st = 0, end = arr.size() - 1;
  return binSearch(arr, tar, st, end);
}
int main()
{
  vector<int> arr = {-1, 0, 3, 5, 9, 12};
  int tar = 9;
  int ans = search(arr, tar);
  cout << "Index : " << ans << endl;
  return 0;
}