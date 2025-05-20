#include <iostream>
using namespace std;
bool isPrime(int num)
{
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int num = 4;

  if (isPrime(num))
  {
    cout << "Prime Number" << endl;
  }
  else
    cout << "Not Prime Number" << endl;

  return 0;
}