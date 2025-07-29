
#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}

void negativeAtBegining(vector<int> &v, int n)
{
  int i = 0, j = n - 1;
  while (i < j)
  {
    if (v[i] > 0)
    {
      i++;
    }
    else if (v[j] <= 0)
    {
      j--;
    }
    else
    {
      swap(v[i], v[j]);
    }
  }
}

int main()
{
  vector<int> v = {1, 8, 3, -4, -5, 6, -2};

  int n = v.size();
  negativeAtBegining(v, n);

  display(v);

  return 0;
}