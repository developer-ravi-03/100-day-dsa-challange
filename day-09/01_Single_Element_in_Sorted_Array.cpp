// Leetcode - 540
//  Single Element In sorted Array
// Brute force apploach
// TC - O(n)
#include <iostream>
#include <vector>
using namespace std;
int SingleElement(vector<int> arr)
{
  int size = arr.size();
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  vector<int> arr = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
  int index = SingleElement(arr);
  cout << "Index of single element : " << index << endl;
  return 0;
}