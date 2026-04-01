class Solution {
public:
    std::stack<std::string> stk;
    std::unordered_set<std::string> mySet = {"+", "-", "*", "/"};
    int evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            if (stk.empty()){
                stk.push(tokens[i]);
            } else if (mySet.contains(tokens[i])) {
                int tmp = std::stoi(stk.top());
                stk.pop();
                if (tokens[i] == "+") {
                    tmp = tmp + std::stoi(stk.top());
                } else if (tokens[i] == "-") {
                    tmp = std::stoi(stk.top()) - tmp;
                } else if (tokens[i] == "*") {
                    tmp = tmp * std::stoi(stk.top());
                } else{
                    tmp = std::stoi(stk.top()) / tmp;
                }
                stk.pop();
                stk.push(std::to_string(tmp));;
            } else {
                stk.push(tokens[i]);
            }
        }
        return std::stoi(stk.top());
    }
};
