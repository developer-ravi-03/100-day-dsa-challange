// optimised approach
// TC- O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> num)
{
  int n = num.size();

  // sort the element
  sort(num.begin(), num.end());

  // print the sorted element
  //  for (int i = 0; i < n; i++)
  //  {
  //    cout << num[i];
  //  }

  int freq = 1;
  int ans = num[0];
  for (int i = 1; i < n; i++)
  {
    if (num[i] == num[i - 1])
    {
      freq++;
    }
    else
    {
      freq = 1;
      ans = num[i];
    }
    if (freq > n / 2)
    {
      return ans;
    }
  }
  return -1;
}
int main()
{
  vector<int> num = {1, 2, 2, 1, 2};

  int element = majorityElement(num);
  cout << "Majority Element: " << element << endl;
  // majorityElement(num);
  return 0;
}