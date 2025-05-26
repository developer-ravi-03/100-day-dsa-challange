// in this we find minimum value of maximum number of pages
// arr=[2,1,3,4]
// 1. s1=2    s2=8
// 2. s1=3    s2=7
// 3. s1=6    s2=4   --> in this case minimum value of maximum number of pages so the answer is 6
// TC=O(n*log n)
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int n, int m, int maximumAllowedPages)
{
  int student = 1, pages = 0;
  for (int i = 0; i < n; i++) // TC= O(n)
  {
    if (arr[i] > maximumAllowedPages)
      return false;
    if (pages + arr[i] <= maximumAllowedPages)
      pages += arr[i];
    else
    {
      student++;
      pages = arr[i];
    }
  }
  return student > m ? false : true;
}

int allocateBooks(vector<int> arr, int n, int m) // O(Nlogn)
{
  if (m > n) // if number of student is greater than number of books than return -1
    return -1;

  int sum = 0;                // for all number sum
  for (int i = 0; i < n; i++) // O(n)
  {
    sum += arr[i];
  }

  int ans = -1;
  int st = 0, end = sum; // range of possible answer

  while (st <= end) // O(logn)
  {
    int mid = st + (end - st) / 2;
    if (isValid(arr, n, m, mid)) // Valid Left
    {
      ans = mid;
      end = mid - 1;
    }
    else // InValid Right
    {
      st = mid + 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {2, 1, 3, 4};
  int n = 4, m = 2;

  cout << allocateBooks(arr, n, m) << endl;
  return 0;
}