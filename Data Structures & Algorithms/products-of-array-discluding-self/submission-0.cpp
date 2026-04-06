class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        vector<int> res(n);

        pref[0] = 1;
        for (int i =1; i < n; ++i){
            pref[i] = nums[i-1] * pref[i-1];
        }
        suff[n-1] = 1;
        for (int j = n-2; j >= 0; --j){
            suff[j] = nums[j+1] * suff[j+1];
        }
        for (int i = 0; i < n; i++){
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};
