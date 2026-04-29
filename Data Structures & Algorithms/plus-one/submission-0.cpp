class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // if 9, make it 0, go to next one

        for (int i = digits.size() - 1; i > -1; --i){
            if ((digits[i] == 9) && (i != 0)){
                digits[i] = 0;
            } else if ((digits[i] == 9) && (i == 0)){
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                return digits;
            }
            else {
                digits[i] += 1;
                return digits;
            }
        }
    }
};
