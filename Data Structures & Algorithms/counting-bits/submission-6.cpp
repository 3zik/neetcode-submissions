class Solution {
public:
    int bit_repr_len(int n){
        // input an int, i want the number of 1s
        unsigned int num = (unsigned int)n;
        int count = 0;
        while(num){
            num &= (num-1);
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) {
        std::vector<int> res;
        for (int i = 0; i <= n; ++i){
            res.push_back(bit_repr_len(i));
        }
        return res;
    }
};
