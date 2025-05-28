// leetcode  -1910
// Remove all Occurance
// TC - O(n)

#include <iostream>
using namespace std;
string removeOccurrences(string s, string part)
{
  while (s.length() > 0 && s.find(part) < s.length())
  {
    s.erase(s.find(part), part.length());
  }
  return s;
}
int main()
{
  string str = "daabcbaabcbc";
  string part = "abc";
  string restPart = removeOccurrences(str, part);
  cout << restPart;
  return 0;
}