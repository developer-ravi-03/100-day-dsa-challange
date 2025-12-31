// Leetcode - 76
// Minimum Window substring
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  string minWindow(string s, string t)
  {
    int n = s.size();
    int m = t.size();
    if (m > n)
      return "";
    vector<int> having(256, 0);
    vector<int> needed(256, 0);
    int minLen = INT_MAX, start = -1;
    int low = 0;
    for (int ch : t)
    {
      needed[ch]++;
    }

    int need = 0;
    int have = 0;
    for (int i = 0; i < 256; i++)
    {
      if (needed[i] > 0)
        need++;
    }

    for (int high = 0; high < n; high++)
    {
      having[s[high]]++;
      if (having[s[high]] > 0 && having[s[high]] == needed[s[high]])
        have++;
      while (have == need)
      {
        int len = high - low + 1;
        if (minLen > len)
        {
          minLen = len;
          start = low;
        }
        having[s[low]]--;

        if (needed[s[low]] > 0 && having[s[low]] < needed[s[low]])
          have--;
        low++;
      }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};
int main()
{
  Solution sol;
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout << sol.minWindow(s, t) << endl;
  return 0;
}