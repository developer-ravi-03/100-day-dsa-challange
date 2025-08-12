#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
   *  Write your code here.
   *  Read input as specified in the question.
   *  Print output as specified in the question.
   */
  int n;
  cin >> n;
  if (n == 0)
    cout << 0;
  if (n == 1)
    cout << 1;
  int fterm = 0, sterm = 1, nterm;
  for (int i = 2; i <= n; i++)
  {
    nterm = fterm + sterm;
    fterm = sterm;
    sterm = nterm;
  }
  if (n > 2)
    cout << nterm;
  return 0;
}