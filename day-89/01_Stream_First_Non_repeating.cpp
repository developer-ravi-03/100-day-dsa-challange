// Stream First Non-repeating
// GFG: Problem of the day
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
  string firstNonRepeating(string &s)
  {
    // code here
    vector<int> freq(26, 0);
    queue<char> q;
    string ans = "";
    for (char c : s)
    {
      freq[c - 'a']++;
      q.push(c);

      while (!q.empty() && freq[q.front() - 'a'] > 1)
      {
        q.pop();
      }

      if (!q.empty())
        ans.push_back(q.front());
      else
        ans.push_back('#');
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  string input = "abadac";
  cout << sol.firstNonRepeating(input) << endl;
  return 0;
}