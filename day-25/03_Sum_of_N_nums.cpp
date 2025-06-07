#include <iostream>
using namespace std;
int sum(int n)
{
  // best case
  if (n == 1)
    return 1;
  return n + sum(n - 1);
}
int main()
{
  int n = 5;
  cout << "" << sum(n) << endl;
  return 0;
}