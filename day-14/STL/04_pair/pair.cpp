#include <iostream>
using namespace std;
int main()
{
  pair<int, int> p = {1, 2};
  cout << "first : " << p.first << endl;
  cout << "second : " << p.second << endl;

  pair<string, int> p1 = {"Ravi", 2};
  cout << "first : " << p1.first << endl;
  cout << "second : " << p1.second << endl;

  pair<char, int> p2 = {'c', 2};
  cout << "first : " << p2.first << endl;
  cout << "second : " << p2.second << endl;

  // pair or pair
  pair<int, pair<string, int>> p3 = {2, {"Ravi", 9}};
  cout << "first : " << p3.first << endl;
  cout << "second.first : " << p3.second.first << endl;
  cout << "second.second : " << p3.second.second << endl;
  return 0;
}