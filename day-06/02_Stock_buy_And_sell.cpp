// leetcode - 121
// stock buy and sell
// in this array find which day to buy and which day to sell the item then return max profit

#include <iostream>
#include <vector>
using namespace std;
int StockBuyAndSell(vector<int> price)
{
  int MaxProfit = 0;
  int bestBuy = price[0];
  // int n = sizeof(price) / sizeof(price[0]);
  int n = price.size();
  for (int i = 0; i < n; i++)
  {
    if (price[i] > bestBuy)
      MaxProfit = max(MaxProfit, price[i] - bestBuy);
    bestBuy = min(bestBuy, price[i]);
  }
  return MaxProfit;
}
int main()
{
  vector<int> price = {7, 1, 5, 3, 6, 4};
  int maxProfit = StockBuyAndSell(price);
  cout << "Maximum Profit : " << maxProfit << endl;
  return 0;
}