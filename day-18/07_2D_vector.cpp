#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6, 10, 11}, {7, 8, 9}, {78}};
  // cout << mat.size() << endl;

  // rows=mat.size()
  // cols=mat[i].size()- ek row ka sara element
  for (int i = 0; i < mat.size(); i++)
  {
    for (int j = 0; j < mat[i].size(); j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}