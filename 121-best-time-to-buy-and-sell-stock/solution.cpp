// 8 ms | 97.3 MB
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // to maximize profit
        // buy at minprice and sell at max price
        //minprice -- minimum price encountered so far
        int minPrice = INT_MAX;
        // maxProfit -- the max profit found so far
        int maxProfit =0;
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i]-minPrice;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};