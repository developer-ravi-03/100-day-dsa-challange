// Police and Thieves
// GFG:Problem Of The Day
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int catchThieves(vector<char> &arr, int k)
  {
    // Code here
    vector<int> police;
    vector<int> thief;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == 'P')
      {
        police.push_back(i);
      }
      else
      {
        thief.push_back(i);
      }
    }

    int i = 0, j = 0;
    int ans = 0;
    while (i < police.size() && j < thief.size())
    {
      if (abs(police[i] - thief[j]) <= k)
      {
        ans++;
        i++;
        j++;
      }
      else if (police[i] < thief[j])
      {
        i++;
      }
      else
      {
        j++;
      }
    }
    return ans;
  }
};
int main()
{
  Solution solution;
  vector<char> arr = {'P', 'T', 'P', 'T', 'T', 'P'};
  int k = 2;
  cout << solution.catchThieves(arr, k) << endl;
  return 0;
}