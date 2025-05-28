// Leetcode - 344
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  string str = "Ravi";
  int st = 0, end = str.length() - 1;
  // while (st <= end)
  // {
  //   swap(str[st], str[end]);
  //   st++;
  //   end--;
  // }

  // another way
  reverse(str.begin(), str.end());
  cout << str;
  return 0;
}