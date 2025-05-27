#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // these all function takes O(1)- TC
  // 1st type - initialisation of vector
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  cout << "size of vec1: " << vec.size() << endl;
  cout << "capacity of vec1: " << vec.capacity() << endl;
  // push_back() - insert the element
  vec.push_back(1);
  vec.push_back(2);

  cout << "after adding more element size of vec1: " << vec.size() << endl;
  cout << "after adding more element capacity of vec1: " << vec.capacity() << endl;

  // for printing
  for (int val : vec)
  {
    cout << val << " ";
  }

  vec.pop_back();
  vec.pop_back();
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  vec.emplace_back(6);
  vec.emplace_back(8);
  cout << endl;
  for (int val : vec)
  {
    cout << val << " ";
  }

  cout << endl;
  cout << "at(5) : " << vec.at(5);

  cout << endl;
  cout << "[5]: " << vec[5];

  cout << endl;
  cout << "front() " << vec.front();

  cout << endl;
  cout << "back() " << vec.back();

  // 2nd type creation
  vector<int> vec0(3, 10); // store same element
  cout << endl;
  for (int val : vec0)
  {
    cout << val << " ";
  }

  // 3rd type creation
  vector<int> vec1 = {1, 5, 4, 3, 2}; // store same element
  cout << endl;
  // vec1.push_back(5);
  for (int val : vec1)
  {
    cout << val << " ";
  }

  // 4th type creating copy vector
  vector<int> vec2(vec1);
  cout << endl;
  vec2.push_back(5);
  for (int val : vec2)
  {
    cout << val << " ";
  }

  return 0;
}