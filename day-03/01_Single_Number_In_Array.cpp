#include <iostream>
using namespace std;
int main()
{
  int arr[] = {4, 1, 2, 1, 2};
  int ans = 0;
  for (int val : arr)
  {
    ans = ans ^ val; // XOR cancel out the same numbers
  }
  cout << "Single numbers in array: " << ans << endl;
  return 0;
}