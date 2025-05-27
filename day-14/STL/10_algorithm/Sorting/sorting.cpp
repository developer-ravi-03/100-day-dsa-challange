#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  int arr[5] = {20, 32, 1, 2, 4};
  sort(arr, arr + 5);
  for (int val : arr)
  {
    cout << val << " ";
  }

  cout << endl;
  sort(arr, arr + 5, greater<int>());
  for (int val : arr)
  {
    cout << val << " ";
  }

  cout << endl;
  vector<int> vec = {20, 32, 1, 2, 4};
  sort(vec.begin(), vec.end());
  for (int val : vec)
  {
    cout << val << " ";
  }

  cout << endl;
  sort(vec.begin(), vec.end(), greater<int>());
  for (int val : vec)
  {
    cout << val << " ";
  }

  cout << endl;
  // reverse(vec.begin(), vec.end());
  reverse(vec.begin() + 1, vec.begin() + 3);
  for (int val : vec)
  {
    cout << val << " ";
  }

  return 0;
}