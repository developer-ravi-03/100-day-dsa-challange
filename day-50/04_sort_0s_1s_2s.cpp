
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

void anotherMethod(vector<int> &v, int n)
{
  int czero = 0, cone = 0, ctwo = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == 0)
    {
      czero++;
    }
    else if (v[i] == 1)
    {
      cone++;
    }
    else
    {
      ctwo++;
    }
  }

    for (int i = 0; i < n; i++)
  {
    if (i < czero)
    {
      v[i] = 0;
    }
    else if (i >= czero && i < cone + czero)
    {
      v[i] = 1;
    }
    else
    {
      v[i] = 2;
    }
  }
}

int main()
{
  vector<int> v = {1, 2, 0, 1, 0, 2, 1, 0};

  int n = v.size();
  anotherMethod(v, n);

  display(v);

  return 0;
}