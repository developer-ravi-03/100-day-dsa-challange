// Minimum Window Subsequence
// GFG:Problem of the day
#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
  string minWindow(string &s1, string &s2)
  {
    // Code here
    int startIdx = -1, minLen = INT_MAX;
    int i = 0;
    int m = s1.size();
    int n = s2.size();
    while (i < m)
    {
      int j = 0;

      // forward scan
      while (i < m)
      {
        if (s1[i] == s2[j])
          j++;
        if (j == n)
        {
          break;
        }
        i++;
      }

      if (j < n)
        break;

      // backward scan
      int end = i;
      j = n - 1;

      while (i >= 0)
      {
        if (s1[i] == s2[j])
        {
          j--;
        }
        if (j < 0)
          break;
        i--;
      }

      int start = i;
      int len = end - start + 1;

      if (len < minLen)
      {
        minLen = len;
        startIdx = start;
      }

      // next search
      i = start + 1;
    }

    if (startIdx == -1)
      return "";
    return s1.substr(startIdx, minLen);
  }
};
int main()
{
  Solution sol;
  string s1 = "geeksforgeeks";
  string s2 = "eksrg";
  cout << sol.minWindow(s1, s2) << endl;
  return 0;
}