// Number of Substrings Containing All Three Characters
// Leetcode : 1358
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int ans = 0;
    int low = 0;
    int n = s.size();
    unordered_map<char, int> mp;
    for (int high = 0; high < n; high++)
    {
      mp[s[high]]++;
      while (mp.size() >= 3)
      {
        ans += (n - high);
        mp[s[low]]--;
        if (mp[s[low]] == 0)
        {
          mp.erase(s[low]);
        }
        low++;
      }
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  string s = "abcabc";
  cout << sol.numberOfSubstrings(s) << endl;
  return 0;
}