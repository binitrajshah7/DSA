class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())
            return false;
        s.erase(val);
        return true;
    }
    
    // advance takes begin iterator to random_index position and returns it to that position
    // now we simply return value of set for that iterator point
    int getRandom() {
        auto it = s.begin();
        int random_index = rand() % s.size();
        advance(it, random_index);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */