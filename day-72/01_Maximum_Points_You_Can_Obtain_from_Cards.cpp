// Maximum Points You Can Obtain from Cards
// Leetcode : 1423
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    // Logic:  n-k is leaving card
    //  Sum of all card
    // ans=sum-min(n-k)
    int sum = 0;
    int minSumOfLeavingCard = INT_MAX;
    int n = cardPoints.size();
    // sum of all cards
    for (int i = 0; i < n; i++)
    {
      sum += cardPoints[i];
    }

    int low = 0, high = n - k;
    int winSum = 0;
    for (int i = low; i < high; i++)
    {
      winSum += cardPoints[i];
    }

    minSumOfLeavingCard = winSum;

    while (high < n)
    {
      low++;
      winSum -= cardPoints[low - 1];
      high++;
      winSum += cardPoints[high - 1];
      minSumOfLeavingCard = min(minSumOfLeavingCard, winSum);
    }
    return sum - minSumOfLeavingCard;
  }
};
int main()
{
  Solution solution;
  vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  int k = 3;
  cout << solution.maxScore(cardPoints, k) << endl;
  return 0;
}