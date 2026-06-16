class Solution {
public:
// bottom up soln
// the idea is, to reach step i, you can only come from i -1 or i -2
    int climbStairs(int n) {
        if (n <= 2) return n;
        std::vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i =3; i <=n;++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
