
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

int main()
{
  vector<int> v = {1, 3, 2, 4, 3, 4, 1, 6, 9};

  // using while loop
  //  int i = 0, j = v.size() - 1;
  //  while (i <= j)
  //  {
  //    swap(v[i], v[j]);
  //    i++;
  //    j--;
  //  }

  // using for loop
  for (int i = 0, j = v.size() - 1; i < j; i++, j--)
  {
    swap(v[i], v[j]);
  }

  display(v);

  return 0;
}