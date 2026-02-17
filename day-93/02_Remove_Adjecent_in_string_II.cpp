// Remove All Adjacent Duplicates in String II
// Leetcode : 1209 ->Method 1
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
  string removeDuplicates(string s, int k)
  {
    int n = s.size();
    stack<pair<char, int>> st;
    for (int i = 0; i < n; i++)
    {
      char c = s[i];

      if (st.empty())
      {
        st.push({c, 1});
        continue;
      }

      if (st.top().first != c)
      {
        st.push({c, 1});
        continue;
      }

      if (st.top().second < (k - 1))
      {
        pair<char, int> p = st.top();
        st.pop();
        st.push({p.first, p.second + 1});
        continue;
      }

      st.pop();
    }

    string ans = "";

    while (!st.empty())
    {
      pair<char, int> p = st.top();
      st.pop();

      while (p.second--)
      {
        ans.push_back(p.first);
      }
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};
int main()
{
  Solution sol;
  string s = "abcd";
  int k = 2;
  cout << sol.removeDuplicates(s, k) << endl;
  return 0;
}