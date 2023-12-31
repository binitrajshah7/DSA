// A node of trie contains can contain 26 character and each character can have link/reference to next node
// flag here signifies the end of a word in a trie
struct Node{
    Node * links[26];
    bool flag = false;

    bool contains_key(char ch){
        return (links[ch-'a'] != NULL);
    }
        
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
        
    Node * get(char ch) {
        return links[ch - 'a'];
    }

    void set_end(){
        flag = true;
    }

    bool is_end(){
        return flag;
    }
};

class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    /* Inserts a word into the trie. */
    // Time Complexity = O(n)
    void insert(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->contains_key(word[i])){
                node->put(word[i], new Node());
            }

            // moves to the reference trie
            node = node->get(word[i]);
        }
        node->set_end();
    }
    
    // Time complexity = O(n) n = size of word
    bool search(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(node->contains_key(word[i]))
                node = node->get(word[i]);
            else    
                return false;
        }
        // verifying if this is the end or not
        return node->is_end();
    }
    
    // Time complexity = O(n) n = size of word
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i=0; i<prefix.size(); i++){
            if(!node->contains_key(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */