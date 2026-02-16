// Daily Temperatures
// Leetcode:739
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
      while (!st.empty() && temperatures[st.top()] <= temperatures[i])
      {
        st.pop();
      }

      if (!st.empty())
      {
        ans[i] = st.top() - i;
      }
      st.push(i);
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result = sol.dailyTemperatures(temperatures);

  cout << "Result: ";
  for (int days : result)
  {
    cout << days << " ";
  }
  cout << endl;
  return 0;
}