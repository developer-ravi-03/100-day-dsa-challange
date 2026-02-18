// First Unique Character in a String
// Leetcode:  387
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int firstUniqChar(string s)
  {
    int n = s.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[s[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
      if (mp[s[i]] < 2)
      {
        return i;
      }
    }
    return -1;
  }
};
int main()
{
  Solution sol;
  string s = "leetcode";
  cout << sol.firstUniqChar(s) << endl;
  return 0;
}