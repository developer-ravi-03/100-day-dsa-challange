// Leetcode: 131
// Pallindrome Partioning
// TC: O(n* 2^n)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string part)
{
  string cp = part;
  reverse(part.begin(), part.end());
  if (cp == part)
  {
    return true;
  }

  return false;
}

void getAllParts(string s, vector<string> &partitions,
                 vector<vector<string>> &ans)
{
  if (s.size() == 0)
  {
    ans.push_back(partitions);
    return;
  }

  for (int i = 0; i < s.size(); i++)
  {
    string part = s.substr(0, i + 1);
    if (isPalindrome(part))
    {
      partitions.push_back(part);
      getAllParts(s.substr(i + 1), partitions, ans);
      partitions.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<string> partitions;
  vector<vector<string>> ans;

  getAllParts(s, partitions, ans);
  return ans;
}
int main()
{
  string s = "aab";
  vector<vector<string>> ans = partition(s);
  for (const auto &part : ans)
  {
    for (const auto &p : part)
    {
      cout << p << ",";
    }
    cout << endl;
  }
  return 0;
}