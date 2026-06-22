class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int maxP = 0;
        while (prices.size() > r){
            if (prices[r] > prices[l]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
