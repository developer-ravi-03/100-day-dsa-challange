// Leetcode - 76
// Minimum Window substring
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  bool check(vector<int> &freqs, vector<int> &freqt)
  {
    for (int i = 0; i < 256; i++)
    {
      if (freqs[i] < freqt[i])
      {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t)
  {
    int low = 0;
    int n = s.size();
    int m = t.size();
    if (m > n)
      return "";
    vector<int> freqt(256, 0);
    vector<int> freqs(256, 0);
    int res = INT_MAX, start = -1;
    for (int ch : t)
    {
      freqt[ch]++;
    }
    for (int high = 0; high < n; high++)
    {
      freqs[s[high]]++;
      while (check(freqs, freqt))
      {
        int len = high - low + 1;
        if (res > len)
        {
          res = len;
          start = low;
        }
        freqs[s[low]]--;
        low++;
      }
    }
    if (res == INT_MAX)
      return "";
    return s.substr(start, res);
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