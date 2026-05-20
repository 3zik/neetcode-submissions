class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxP = 0;
        int timeline = prices.size();
        while (r<timeline){
            if (prices[r] > prices[l]){
                maxP = max(prices[r] - prices[l], maxP);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
