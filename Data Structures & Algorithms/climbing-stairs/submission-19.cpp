class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) {
        memo.resize(n, -1);
        return dfs(n, 0);    
    }
    int dfs(int n, int i){
        if (i > n) return 0;
        if (i == n) return 1;
        if (memo[i] != -1) return memo[i];

        return memo[i] = dfs(n, i + 1) + dfs(n, i + 2);
    }
};
