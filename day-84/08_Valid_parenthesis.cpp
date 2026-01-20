// Valid Parenthesis
// Leetcode: 20
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    stack<char> st;
    bool isValid(string s)
    {
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                if (st.top() == '(' && c == ')' ||
                    st.top() == '{' && c == '}' ||
                    st.top() == '[' && c == ']')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main()
{
    Solution sol;
    string test1 = "()";
    string test2 = "([{}])";
    string test3 = "([)]";

    cout << "Test 1: " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    sol.st = stack<char>();
    cout << "Test 2: " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    sol.st = stack<char>();
    cout << "Test 3: " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl;
    return 0;
}