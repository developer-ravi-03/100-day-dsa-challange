// // brute force approach
#include <iostream>
using namespace std;
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = 5, count = 0;

  // int st=0;
  // int en = n - 1;
  for (int st = 0; st < n; st++)
  {
    for (int en = st; en < n; en++)
    {
      for (int i = st; i <= en; i++)
      {
        cout << arr[i];
        if (i < en)
          cout << " "; // add space between elements
      }
      count++; // count subarray after printing
      cout << endl;
    }
  }

  cout << "Total number of subarrays: " << count << endl;
  return 0;
}
