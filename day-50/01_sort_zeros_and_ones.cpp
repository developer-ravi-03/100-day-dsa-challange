
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
  int zero = 0, one = 1;
  int i = 0, j = n - 1;
  while (i < j)
  {
    if (v[i] == zero)
    {
      i++;
    }
    else if (v[j] == one)
    {
      j--;
    }
    else
    {
      swap(v[i], v[j]);
    }
  }
}

void anotherMethod(vector<int> &v, int n)
{
  int czero = 0, cone = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == 0)
    {
      czero++;
    }
    else
    {
      cone++;
    }
  }

  // first method
  //  for (int i = 0; i < czero; i++)
  //  {
  //    v[i] = 0;
  //  }
  //  for (int i = czero; i < n; i++)
  //  {
  //    v[i] = 1;
  //  }

  // second method
  for (int i = 0; i < n; i++)
  {
    if (i < czero)
    {
      v[i] = 0;
    }
    else
    {
      v[i] = 1;
    }
  }
}

int main()
{
  vector<int> v = {1, 1, 0, 1, 0, 1, 1, 0};

  int n = v.size();
  sortArray(v, n);
  // anotherMethod(v, n);

  display(v);

  return 0;
}