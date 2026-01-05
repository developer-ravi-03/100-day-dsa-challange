// Number of Substrings Containing All Three Characters
// Leetcode : 1358
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int lastSeen[3] = {-1, -1, -1};
    int res = 0;
    for (int high = 0; high < s.size(); high++)
    {
      lastSeen[s[high] - 'a'] = high;
      if (lastSeen[0] > -1 && lastSeen[1] > -1 && lastSeen[2] > -1)
      {
        res += min(min(lastSeen[0], lastSeen[1]), lastSeen[2]) + 1;
      }
    }
    return res;
  }
};
int main()
{
  Solution sol;
  string s = "abcabc";
  cout << sol.numberOfSubstrings(s) << endl;
  return 0;
}