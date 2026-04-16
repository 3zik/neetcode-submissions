// SPACE-OPTIMIZED BOTTOM UP / TABULATION SOLN

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int tmp;
        for(int i = 2; i<n+1; i++){
            tmp = a;
            a = a+b;
            b = tmp;
        }
        return a;
    }
};
