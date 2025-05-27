#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  cout << "Max: " << *(max_element(v.begin(), v.end())) << endl;
  cout << "Min: " << *(min_element(v.begin(), v.end())) << endl;
  int target = 2;
  cout << "binary search: " << binary_search(v.begin(), v.end(), target) << endl;

  int n = 15;
  long int n1 = 15;
  long long int n2 = 15;
  cout << "builtin: " << __builtin_popcount(n) << endl;
  cout << "long builtin: " << __builtin_popcountl(n1) << endl;
  cout << "long long builtin: " << __builtin_popcountll(n2) << endl;

  return 0;
}