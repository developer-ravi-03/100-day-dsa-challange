// Leetcode:509
// TC: 2^n
//  accurate TC: (1.628)^n
// fibonacci number
#include <iostream>
using namespace std;
int fibonacci(int n)
{
  if (n == 0 || n == 1)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
  int n = 6;
  cout << " " << fibonacci(n) << endl;
  return 0;
}