// Leetcode - 852
//  Peek index in Mountain array
// O (log n)
#include <iostream>
#include <vector>
using namespace std;
int PeekIndex(vector<int> arr)
{
  int size = arr.size();
  int st = 1, end = size - 2; // start from 1 and end because first element ans last element cant be beek index
  while (st <= end)
  {
    int mid = st + (end - st) / 2;
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
    {
      return mid;
    }

    if (arr[mid - 1] < arr[mid])
    {
      st = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
}
int main()
{
  vector<int> arr = {3, 4, 5, 6, 7, 2, 1, 0};
  int index = PeekIndex(arr);
  cout << "Index of element : " << index << endl;
  return 0;
}