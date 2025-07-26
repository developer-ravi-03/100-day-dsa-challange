
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

void reversePart(int i, int j, vector<int> &v)
{
  while (i <= j)
  {
    swap(v[i], v[j]);
    i++;
    j--;
  }
}

int main()
{
  vector<int> v = {1, 6, 2, 3, 7, 4};
  int k = 8;
  int n = v.size();
  if (k > n)
  {
    k = k % n;
  }

  reversePart(0, n - k - 1, v);
  reversePart(n - k, n - 1, v);
  reversePart(0, n - 1, v);

  display(v);

  // 1 6 2 3 7 4
  // 7 4 1 6 2 3
  return 0;
}