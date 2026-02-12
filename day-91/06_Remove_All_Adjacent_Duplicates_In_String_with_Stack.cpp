// Remove All Adjacent Duplicates In String with Stack
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
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
      if (!st.empty() && st.top() == s[i])
      {
        st.pop();
      }
      else
      {
        st.push(s[i]);
      }
    }

    string res = "";
    while (!st.empty())
    {
      char ch = st.top();
      st.pop();
      res.push_back(ch);
    }
    reverse(res.begin(), res.end());
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