// Leetcode - 204
// Count Prime
// Sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
  vector<bool> isPrime(n + 1, true);
  int count = 0;

  for (int i = 2; i < n; i++)
  {
    if (isPrime[i])
    {
      count++;

      for (int j = i * 2; j < n; j = j + i)
      {
        isPrime[j] = false;
      }
    }
  }
  return count;
}
int main()
{
  int n = 50;
  int count = countPrimes(n);
  cout << "Total number of Prime number are: " << count << endl;
  return 0;
}