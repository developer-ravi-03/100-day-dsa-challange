// Leetcode : 387
// TC : O(n)
// SC : O(n)
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> m;
    queue<int> q; // viable ans
    for (int i = 0; i < s.size(); i++)
    {
      if (m.find(s[i]) == m.end())
      {
        q.push(i);
      }

      m[s[i]]++; // increase freq

      while (q.size() > 0 && m[s[q.front()]] > 1)
        q.pop();
    }

    if (q.empty())
      return -1;
    else
      return q.front();
  }
};

int main()
{
  string s;
  cout << "Enter String : ";
  cin >> s;
  Solution sol;
  cout << sol.firstUniqChar(s) << endl;
  return 0;
}