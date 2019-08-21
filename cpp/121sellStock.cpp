class Solution {
public:
  int maxProfit(vector<int>& prices) {
      int sum = 0, profit = 0;
      for(int i = 1; i <prices.size(); i++){
          sum = max(0, sum + prices[i] - prices[i-1]);
          profit = max(profit, sum);
      }
      return profit;
  }
};
