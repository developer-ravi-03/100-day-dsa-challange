#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  vector<char> character = {'c', 'h', 'a', 'r'};
  for (int i = 0; i < character.size(); i++)
  {
    cout << character[i];
  }
  character.push_back('a');
  character.push_back('r');
  cout << endl;
  cout << "All elements after adding: ";
  for (int i = 0; i < character.size(); i++)
  {
    cout << character[i];
  }

  cout << endl;
  cout << "Creating string vector: ";
  vector<string> stringVector = {"Hello", "World"};
  stringVector.push_back("Ravi");

  for (int i = 0; i < stringVector.size(); i++)
  {
    cout << stringVector[i] << " ";
  }

  return 0;
}