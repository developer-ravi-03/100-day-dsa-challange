// Longest Palindrome
// Leetcode: 409
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution
{
public:
  int longestPalindrome(string s)
  {
    int n = s.size();
    if (n == 0)
      return 0;
    unordered_map<char, int> mp;
    for (char ch : s)
    {
      mp[ch]++;
    }

    int ans = 0;
    bool isOdd = false;
    for (auto i : mp)
    {
      if (i.second % 2 == 0)
      {
        ans += i.second;
      }
      else
      {
        ans += (i.second - 1);
        isOdd = true;
      }
    }

    return (isOdd ? ans + 1 : ans);
  }
};
int main()
{
  Solution sol;
  string s = "abccccdd";
  cout << sol.longestPalindrome(s) << endl;
  return 0;
}