class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int buy = prices[0];

      for(int i=1; i<prices.size(); i++){
            int price = prices[i];

            if(price < buy){
                buy = price;
            }
            else{
                profit = max(profit, price-buy);
            }
      }
       return profit; 
    }
};