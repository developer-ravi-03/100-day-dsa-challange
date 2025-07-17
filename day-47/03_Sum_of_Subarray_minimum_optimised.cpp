#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
  int n = arr.size();
  const int MOD = 1e9 + 7;

  vector<int> left(n), right(n);
  stack<pair<int, int>> s1, s2;

  // Calculate how many elements are greater than arr[i] to the left
  for (int i = 0; i < n; ++i)
  {
    int count = 1;
    while (!s1.empty() && s1.top().first > arr[i])
    {
      count += s1.top().second;
      s1.pop();
    }
    left[i] = count;
    s1.push({arr[i], count});
  }

  // Calculate how many elements are greater than or equal to arr[i] to the right
  for (int i = n - 1; i >= 0; --i)
  {
    int count = 1;
    while (!s2.empty() && s2.top().first >= arr[i])
    {
      count += s2.top().second;
      s2.pop();
    }
    right[i] = count;
    s2.push({arr[i], count});
  }

  // Final result: sum of all contributions
  long long result = 0;
  for (int i = 0; i < n; ++i)
  {
    result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
  }

  return (int)result;
}

// Example usage
int main()
{
  vector<int> arr = {3, 1, 2, 4};
  cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl;
  return 0;
}
