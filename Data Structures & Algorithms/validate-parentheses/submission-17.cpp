class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() < 2) return false; 
        for (char ch : s){
            if (ch == '{' || ch == '(' || ch == '['){
                st.push(ch);
            }
            else if (ch == '}'){
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
            else if (ch == ')'){
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            }
            else if (ch == ']'){
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            }
            else { return false; }
        }
        return st.empty();
    }
};
