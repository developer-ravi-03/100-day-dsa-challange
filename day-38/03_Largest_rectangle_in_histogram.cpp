// Leetcode : 84
// Largest Rectangle in histogram
// TC : O(n)
// SC : O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> left(n, 0);  // left smaller nearest
    vector<int> right(n, 0); // right smaller nearest
    stack<int> s;

    // right smaller
    for (int i = n - 1; i >= 0; i--)
    {
      while (s.size() > 0 && heights[s.top()] >= heights[i])
      {
        s.pop();
      }
      right[i] = s.empty() ? n : s.top();
      s.push(i);
    }

    // emty the stack for reuse that
    while (!s.empty())
    {
      s.pop();
    }

    // left smaller
    for (int i = 0; i < n; i++)
    {
      while (s.size() > 0 && heights[s.top()] >= heights[i])
      {
        s.pop();
      }
      left[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }

    // calcutate ans
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int width = right[i] - left[i] - 1;
      int currArea = heights[i] * width;
      ans = max(ans, currArea);
    }

    return ans;
  }
};
int main()
{
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  Solution sol;
  cout << sol.largestRectangleArea(heights) << endl;
  return 0;
}
