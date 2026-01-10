// Substrings with K Distinct
// GFG: Problem of the day
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int countArr(string &s, int k)
  {
    if (k < 0)
      return 0;
    // unordered_map<char,int>mp;
    vector<int> freq(26, 0);
    int distinct = 0;
    int low = 0;
    int subArr = 0;
    for (int high = 0; high < s.size(); high++)
    {
      if (freq[s[high] - 'a'] == 0)
        distinct++;

      freq[s[high] - 'a']++;

      while (distinct > k)
      {
        freq[s[low] - 'a']--;
        if (freq[s[low] - 'a'] == 0)
          distinct--;
        low++;
      }
      subArr += (high - low + 1);
    }
    return subArr;
  }
  int countSubstr(string &s, int k)
  {
    // code here
    return countArr(s, k) - countArr(s, k - 1);
  }
};
int main()
{
  Solution sol;
  string s = "aabacbebebe";
  int k = 3;
  cout << sol.countSubstr(s, k) << endl;
  return 0;
}