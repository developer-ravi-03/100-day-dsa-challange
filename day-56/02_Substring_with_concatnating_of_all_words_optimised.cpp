// Leectode - 30
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {

    int m = words[0].size();
    int n = words.size();
    int tl = m * n;
    unordered_map<string, int> mp1;
    vector<int> ans;
    for (auto word : words)
    {
      mp1[word]++;
    }
    if (tl > s.size())
    {
      return ans;
    }

    for (int i = 0; i < m; i++)
    {

      unordered_map<string, int> mp2;
      int left = i;
      for (int j = i; j <= s.size() - m; j += m)
      {
        string temp = s.substr(j, m);

        if (mp1.find(temp) != mp1.end())
        {
          mp2[temp]++;

          while (mp2[temp] > mp1[temp])
          {
            mp2[s.substr(left, m)]--;
            left += m;
          }
          if (j - left + m == tl)
          {
            ans.push_back(left);
            mp2[s.substr(left, m)]--;
            left += m;
          }
        }
        else
        {
          mp2.clear();
          left = j + m;
        }
      }
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  string s = "barfoofoothefoofoobarman";
  vector<string> words = {"foo", "bar"};
  vector<int> result = sol.findSubstring(s, words);
  for (int idx : result)
  {
    cout << idx << " ";
  }
  cout << endl;
  return 0;
}