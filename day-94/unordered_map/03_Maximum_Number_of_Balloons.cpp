// Maximum Number of Balloons
// Leetcode:1189
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
class Solution
{
public:
  int maxNumberOfBalloons(string text)
  {
    unordered_map<char, int> have;
    unordered_map<char, int> need;

    for (char ch : text)
    {
      have[ch]++;
    }

    string bl = "balloon";

    for (char ch : bl)
    {
      need[ch]++;
    }

    int ans = INT_MAX;

    for (auto i : need)
    {
      char c = i.first;
      int fneed = i.second;
      int fhave = have[c];
      int times = fhave / fneed;
      ans = min(ans, times);
    }

    return ans;
  }
};
int main()
{
  Solution sol;
  string text = "loonbalxballpoon";
  cout << sol.maxNumberOfBalloons(text) << endl;
  return 0;
}