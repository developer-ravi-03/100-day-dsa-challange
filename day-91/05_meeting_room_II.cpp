// Meeting Rooms II
// GFG
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  int minMeetingRooms(vector<int> &start, vector<int> &end)
  {
    // code here
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int n = start.size();
    int i = 0, j = 0;
    int res = 0, room = 0;
    while (i < n && j < n)
    {
      if (start[i] < end[j])
      {
        room++;
        res = max(room, res);
        i++;
      }
      else
      {
        room--;
        j++;
      }
    }
    return res;
  }
};

int main()
{
  Solution obj;
  vector<int> start = {0, 5, 15};
  vector<int> end = {10, 20, 30};
  cout << obj.minMeetingRooms(start, end) << endl;
  return 0;
}