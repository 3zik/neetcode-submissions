class Solution {
public:

    bool isValid(string s) {
        stack<char> ponis;
        unordered_map<char, char> options = {{')','('}, {']', '['}, {'}', '{'}};
        for (char i : s) {
            if (options.count(i)) {
                if (!ponis.empty() && ponis.top() == options[i]){
                    ponis.pop();
                } else {
                    return false;
                }
            } else {
                ponis.push(i);
            }
       }
       return ponis.empty();
    }
};
