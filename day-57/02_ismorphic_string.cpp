// Leetcode - 205
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> smp, tmp;
    for (int i = 0; i < s.size(); i++)
    {
      char s1 = s[i], t1 = t[i];

      if (smp.count(s1) && smp[s1] != t1)
        return false;
      if (tmp.count(t1) && tmp[t1] != s1)
        return false;

      smp[s1] = t1;
      tmp[t1] = s1;
    }
    return true;
  }
};
int main()
{
  Solution sol;
  string s = "egg";
  string t = "add";
  cout << boolalpha << sol.isIsomorphic(s, t) << endl;

  s = "foo";
  t = "bar";
  cout << boolalpha << sol.isIsomorphic(s, t) << endl;

  s = "paper";
  t = "title";
  cout << boolalpha << sol.isIsomorphic(s, t) << endl;
  return 0;
}