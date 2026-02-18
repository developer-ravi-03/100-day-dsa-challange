// First Unique Character in a String
// Leetcode:  387
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    unordered_map<char, int> r;
    unordered_map<char, int> m;

    for (char c : ransomNote)
    {
      r[c]++;
    }

    for (char c : magazine)
    {
      m[c]++;
    }

    for (char c : ransomNote)
    {
      if (r[c] <= m[c])
      {
        continue;
      }
      else
      {
        return false;
      }
    }
    return true;
  }
};
int main()
{
  Solution sol;
  string ransomNote = "a";
  string magazine = "b";
  cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

  ransomNote = "a";
  magazine = "b";
  cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

  ransomNote = "aa";
  magazine = "ab";
  cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;

  ransomNote = "aa";
  magazine = "aab";
  cout << (sol.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;
  return 0;
}