class TrieNode{
public:
    unordered_map<char, TrieNode*> mp;
    bool endOfWord = false;
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word){
            if (!curr->mp.contains(ch)){
                curr->mp[ch] = new TrieNode();
            }
            curr = curr->mp[ch];            
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word){
            if (!curr->mp.contains(ch)){
                return false;
            }
            curr = curr->mp[ch];            
        }
        return (curr->endOfWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix){
            if (!curr->mp.contains(ch)){
                return false;
            }
            curr = curr->mp[ch];            
        }
        return true;
    }
};
