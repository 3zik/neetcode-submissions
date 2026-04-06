class Solution {
public:

    string encode(vector<string>& strs) {
        string outputStr;
        for(string i : strs){
            string myStr = to_string(i.size());
            myStr.push_back('#');
            outputStr+=myStr+=i;
        }
        return outputStr;
    }

    vector<string> decode(string s) {
        vector<string> resultStr;
        int i = 0;

        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);
            resultStr.push_back(word);

            i = j+1+len;

        }
        return resultStr;
    }
};
