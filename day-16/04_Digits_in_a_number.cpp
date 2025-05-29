// O(logbase10)
#include <iostream>
using namespace std;

void printDigits(int n)
{
  int count = 0, sum = 0;
  while (n != 0)
  {
    int digit = n % 10;
    cout << digit << endl;
    count++;
    sum += digit;
    n /= 10;
  }
  cout << "count : " << count << endl;
  cout << "sum : " << sum << endl;
}
int main()
{
  int n = 3987;
  printDigits(n);
  return 0;
}