#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> vec = {1, 2, 3, 4, 5};

  cout << "1D vector of integers: ";
  // Access elements
  for (int i = 0; i < vec.size(); ++i)
  {
    cout << vec[i] << " ";
  }

  return 0;
}
