// leetcode  - 151
// Reverse Words in a String
// TC- O(n)
#include <iostream>
#include <algorithm>
using namespace std;
string reverseWords(string s)
{
  int n = s.length();
  string ans = "";

  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++)
  {
    string word = "";
    while (i < n && s[i] != ' ')
    {
      word += s[i];
      i++;
    }

    reverse(word.begin(), word.end());
    if (word.length() > 0)
    {
      ans += " " + word;
    }
  }
  return ans.substr(1);
}
int main()
{
  string s = "the sky is blue";
  string revesedWord = reverseWords(s);
  cout << revesedWord;
  return 0;
}