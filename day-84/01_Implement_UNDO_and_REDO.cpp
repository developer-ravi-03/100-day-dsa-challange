// Implement UNDO & REDO
// GFG: Problem of the day
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  string str;
  vector<char> vec;
  void append(char x)
  {
    // append x into document
    str.push_back(x);
  }

  void undo()
  {
    // undo last change
    vec.push_back(str[str.size() - 1]);
    str.pop_back();
  }

  void redo()
  {
    // redo changes
    if (vec.size() == 0)
      return;
    str.push_back(vec[vec.size() - 1]);
    vec.pop_back();
  }

  string read()
  {
    // read the document
    return str;
  }
};
int main()
{
  Solution sol;
  sol.append('a');
  sol.append('b');
  sol.append('c');
  cout << "Document: " << sol.read() << endl;

  sol.undo();
  cout << "After undo: " << sol.read() << endl;

  sol.redo();
  cout << "After redo: " << sol.read() << endl;

  sol.append('d');
  cout << "After append 'd': " << sol.read() << endl;
  return 0;
}