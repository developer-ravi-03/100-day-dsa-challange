// Expression contains redundant bracket or not
// GFG : problem of the day
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
  bool checkRedundancy(string &s)
  {
    // code here
    stack<int> st;
    for (char ch : s)
    {
      if (ch == ')')
      {
        bool hasOperator = false;

        while (!st.empty() && st.top() != '(')
        {
          char top = st.top();
          st.pop();

          if (top == '+' || top == '-' || top == '*' || top == '/')
          {
            hasOperator = true;
          }
        }

        if (!st.empty())
          st.pop();

        if (!hasOperator)
          return true;
      }
      else
      {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
          st.push(ch);
        }
      }
    }

    return false;
  }
};

int main()
{
  Solution sol;
  string test1 = "((a+b))";
  string test2 = "(a+b)";
  string test3 = "(a+(b*c))";

  cout << "Test 1: " << (sol.checkRedundancy(test1) ? "Has redundancy" : "No redundancy") << endl;
  cout << "Test 2: " << (sol.checkRedundancy(test2) ? "Has redundancy" : "No redundancy") << endl;
  cout << "Test 3: " << (sol.checkRedundancy(test3) ? "Has redundancy" : "No redundancy") << endl;
  return 0;
}