#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getPerms(string &s, int idx, vector<string> &ans)
{
  if (idx == s.size())
  {
    ans.push_back(s);
    return;
  }

  for (int i = idx; i < s.size(); i++)
  {
    swap(s[idx], s[i]); // choose ith character for idx position
    getPerms(s, idx + 1, ans);
    swap(s[idx], s[i]); // backtrack
  }
}

int main()
{
  string str = "abc";
  vector<string> ans;
  getPerms(str, 0, ans);

  for (const auto &perm : ans)
  {
    cout << perm << endl;
  }

  return 0;
}
