#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int m = 3, n = 3;

  vector<int> ans;

  int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
  while (srow <= erow && scol <= ecol)
  {

    // top
    for (int j = scol; j <= ecol; j++)
    {
      ans.push_back(arr[srow][j]);
    }

    // right
    for (int i = srow + 1; i <= erow; i++)
    {
      ans.push_back(arr[i][ecol]);
    }

    // bottom
    for (int j = ecol - 1; j >= scol; j--)
    {
      if (srow == erow)
      {
        break;
      }

      ans.push_back(arr[erow][j]);
    }

    // left
    for (int i = erow - 1; i >= srow + 1; i--)
    {
      if (scol == ecol)
      {
        break;
      }
      ans.push_back(arr[i][scol]);
    }
    srow++;
    scol++;
    erow--;
    ecol--;
  }

  // for (int i = 0; i < ans.size() - 1; i++)
  // {
  //   cout << ans[i];
  // }

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i];
    if (i != ans.size() - 1)
    {
      cout << " ";
    }
  }

  return 0;
}