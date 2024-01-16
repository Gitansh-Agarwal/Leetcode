class RandomizedSet {
public:
    unordered_map<int, int> pos;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.find(val)!=pos.end())
            return 0;
        pos[val] = 1;
        return 1;
    }
    
    bool remove(int val) {
        if(pos.find(val)==pos.end())
            return 0;
        pos.erase(val);
        return 1;
    }
    
    int getRandom() {
        return next(pos.begin(), rand() % pos.size()) -> first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */