// Count Residue Prefixes
// Leetcode:3803
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int residuePrefixes(string s)
  {
    unordered_map<char, int> mp;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i]]++;

      int distinct = mp.size();
      int len = i + 1;

      if (distinct == len % 3)
      {
        ans++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  string s = "aabcab";
  cout << sol.residuePrefixes(s) << endl;
  return 0;
}