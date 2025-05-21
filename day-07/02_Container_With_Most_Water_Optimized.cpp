// Leetcode- 11
// container with most water
// 2- pointer Approach
// TC- O(n)
#include <iostream>
#include <vector>
using namespace std;
int MaxArea(vector<int> height)
{
  int maxWater = 0;
  int n = height.size();
  int lp = 0, rp = n - 1;
  while (lp < rp)
  {
    int width = rp - lp;
    int containerHeight = min(height[lp], height[rp]);
    int area = containerHeight * width;
    maxWater = max(maxWater, area);
    if (height[lp] < height[rp])
    {
      lp++;
    }
    else
    {
      rp--;
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