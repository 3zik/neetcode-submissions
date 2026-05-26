class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        while (digits[n] == 9){
            digits[n]=0;
            if (n == 0){
                digits.insert(digits.begin(), 1);
                return digits;
            }
            n--;
        }
        digits[n] +=1;
        return digits;
    }
};
