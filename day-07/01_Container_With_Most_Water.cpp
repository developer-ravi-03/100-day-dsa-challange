// Leetcode- 11
// container with most water
// Brute Force Approach
// TC- O(nSquare)
#include <iostream>
#include <vector>
using namespace std;
int MaxArea(vector<int> height)
{
  int maxWater = 0;
  int n = height.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int width = j - i;
      int containerHeight = min(height[i], height[j]);
      int area = containerHeight * width;
      maxWater = max(maxWater, area);
    }
  }
  return maxWater;
}
int main()
{
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int MaxWater = MaxArea(height);
  cout << "MaxWater: " << MaxWater << endl;
  return 0;
}