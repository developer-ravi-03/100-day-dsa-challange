// two sum
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// first method
int lastOccurance(vector<int> &arr, int tar)
{
  int n = arr.size();
  int idx = -1;
  for (int i = 0; i < n; i++)
  {
    if (tar == arr[i])
      idx = i;
  }
  return idx;
}

// second method
int secondMethod(vector<int> &arr, int tar)
{
  int n = arr.size();
  int idx = -1;
  for (int i = n; i >= 0; i--)
  {
    if (tar == arr[i])
    {
      idx = i;
      break;
    }
  }
  return idx;
}

int main()
{
  vector<int> arr = {1, 3, 2, 4, 3, 4, 1, 6};
  int tar = 3;
  // int idx = lastOccurance(arr, tar);
  int idx = secondMethod(arr, tar);
  cout << "idx:" << idx;
  return 0;
}