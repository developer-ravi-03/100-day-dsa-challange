// moore's Algorithm
// TC - O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> num)
{
  int n = num.size();
  int freq = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (freq == 0)
      ans = num[i];
    if (ans == num[i])
      freq++;
    else
      freq--;
  }
  // for return -1 if answer is not available
  int count = 0;
  for (int val : num)
  {
    if (val == ans)
      count++;
  }

  if (count > n / 2)
  {
    return ans;
  }

  return -1;
  // return ans;
}
int main()
{
  vector<int> num = {1, 2, 2, 1, 2};

  int element = majorityElement(num);
  cout << "Majority Element: " << element << endl;
  // majorityElement(num);
  return 0;
}