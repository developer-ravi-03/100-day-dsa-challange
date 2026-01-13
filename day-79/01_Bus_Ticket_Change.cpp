#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  bool canServe(vector<int> &arr)
  {
    // code here
    int ctF = 0;
    int ctT = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == 5)
      {
        ctF++;
      }
      else if (arr[i] == 10)
      {
        if (ctF > 0)
        {
          ctF--;
          ctT++;
        }
        else
        {
          return false;
        }
      }
      else
      {
        if (ctF > 0 && ctT > 0)
        {
          ctF--;
          ctT--;
        }
        else if (ctF > 2)
        {
          ctF -= 3;
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {5, 5, 5, 10, 10, 20};
  if (sol.canServe(arr))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}