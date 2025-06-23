#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string str)
  {
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[')
      { // opening
        st.push(str[i]);
      }
      else
      { // closing
        if (st.size() == 0)
          return false; // closing > opening
        if (st.top() == '(' && str[i] == ')' ||
            st.top() == '{' && str[i] == '}' ||
            st.top() == '[' && str[i] == ']')
        {
          st.pop();
        }
        else
        {
          return false;
        }
      }
    }

    return st.size() == 0; // open > closing
  }
};

int main()
{
  Solution sol;
  string input;
  cout << "Enter a string of parentheses: ";
  cin >> input;
  if (sol.isValid(input))
  {
    cout << "Valid Parenthesis" << endl;
  }
  else
  {
    cout << "Invalid Parenthesis" << endl;
  }
  return 0;
}