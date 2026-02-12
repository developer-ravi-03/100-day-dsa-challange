// Remove All Adjacent Duplicates In String with vector
// Leetcode : 1047
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
  string removeDuplicates(string s)
  {
    string res = "";
    for (char ch : s)
    {
      if (!res.empty() && res.back() == ch)
      {
        res.pop_back();
      }
      else
      {
        res.push_back(ch);
      }
    }
    return res;
  }
};
int main()
{
  Solution sol;
  string input = "abbaca";
  string output = sol.removeDuplicates(input);
  cout << "Input: " << input << endl;
  cout << "Output: " << output << endl;
  return 0;
}