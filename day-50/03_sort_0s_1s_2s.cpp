
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void display(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}

void sortArray(vector<int> &v, int n)
{
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high)
  {
    if (v[mid] == 0)
    {
      swap(v[mid], v[low]);
      mid++;
      low++;
    }
    else if (v[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(v[mid], v[high]);
      high--;
    }
  }
}

int main()
{
  vector<int> v = {1, 2, 0, 1, 2, 1, 1, 0};

  int n = v.size();
  sortArray(v, n);

  display(v);

  return 0;
}