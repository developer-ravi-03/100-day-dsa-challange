#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> num)
{
  int n = num.size();

  for (int val : num)
  {
    int freq = 0;
    for (int element : num)
    {
      if (element == val)
      {
        freq++;
        // cout << element;
      }
    }
    if (freq > n / 2)
    {
      return val;
    }
  }
  return -1;
}
int main()
{
  vector<int> num = {1, 2, 1, 2, 2};

  int element = majorityElement(num);
  cout << "Majority Element: " << element << endl;
  return 0;
}