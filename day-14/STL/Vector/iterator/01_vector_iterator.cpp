#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> vec = {2, 4, 6, 8, 3, 9, 5, 89};

  cout << "begin() : " << *(vec.begin()) << endl;
  cout << "end() : " << *(vec.end()) << endl;

  vector<int>::iterator it;
  for (it = vec.begin(); it != vec.end(); it++)
  {
    cout << *(it) << " ";
  }

  cout << endl;
  vector<int>::reverse_iterator it1;
  for (it1 = vec.rbegin(); it1 != vec.rend(); it1++)
  {
    cout << *(it1) << " ";
  }

  // type 3
  cout << endl;
  for (vector<int>::reverse_iterator it2 = vec.rbegin(); it2 != vec.rend(); it2++)
  {
    cout << *(it2) << " ";
  }

  // type 4 - with auto
  cout << endl;
  for (auto it3 = vec.rbegin(); it3 != vec.rend(); it3++)
  {
    cout << *(it3) << " ";
  }

  cout << endl;
  for (auto it4 = vec.begin(); it4 != vec.end(); it4++)
  {
    cout << *(it4) << " ";
  }

  return 0;
}