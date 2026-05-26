class Solution {
public:
    int sum_of_squares(int n){
        std::string temp_s = std::to_string(n);
        int res = 0;
        for (char c : temp_s){
            int digit = c - '0';
            res += (digit*digit);
        }
        return res;
    }

    bool isHappy(int n) {
        std::unordered_set<int> seen;
        while (!seen.contains(1)) {
            if (!seen.contains(n)) {
                seen.insert(n);
            } else {
                return false;
            }
            n = sum_of_squares(n);
        }
        return true;
    }
};
