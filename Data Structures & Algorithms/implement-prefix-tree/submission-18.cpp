class TrieNode{
public:
    unordered_map<char, TrieNode*> mp;
    bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word){
            if (!curr->mp.contains(c)){
                curr->mp[c] = new TrieNode();
            }
            curr = curr->mp[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word){
            if (!curr->mp.contains(c)){
                return false;
            }
            curr = curr->mp[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix){
            if (!curr->mp.contains(c)){
                return false;
            }
            curr = curr->mp[c];
        }
        return true;
    }
};
