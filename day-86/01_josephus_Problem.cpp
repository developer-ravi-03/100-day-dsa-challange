// Josephus problem
// Problem of the day : GFG
// Logic
// Josephus Problem:
// - Reduce problem size
// - Adjust index by k
// - Use modulo for circular behavior
#include <iostream>
using namespace std;
class Solution
{
public:
  int findIdx(int n, int k)
  {
    if (n == 1)
      return 0;
    // it uses 0 based Indexing
    return (findIdx(n - 1, k) + k) % n;
  }
  int josephus(int n, int k)
  {
    // code here
    // it uses 0 based Indexing so we have to add +1 index for 1 based indexing
    return findIdx(n, k) + 1;
  }
};
int main()
{
  Solution sol;
  int n = 5, k = 2;
  cout << "Josephus position: " << sol.josephus(n, k) << endl;
  return 0;
}