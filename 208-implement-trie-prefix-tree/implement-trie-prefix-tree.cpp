class Trie {
public:
    unordered_map<string, int> mpp, mp;
    Trie() {
    }
    
    void insert(string word) {
        mpp[word]++;
        string s;
        for(int i=0; i<word.length(); i++){
            s += word[i];
            mp[s]++;
        }
    }
    
    bool search(string word) {
        if(mpp.find(word) != mpp.end())
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp[prefix])
            return true;
        return false;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */