class RandomizedSet {
public:
    //1st Method
    // unordered_map<int, int> pos;
    
    //2nd Method
    unordered_map<int, int> pos;
    vector<int> values;
    
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        //1st Method
        // if(pos.find(val)!=pos.end())
        //     return 0;
        // pos[val] = 1;
        // return 1;
        
        
        //2nd Method
        if(pos.find(val) != pos.end())
            return 0;
        pos[val] = values.size();
        values.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        //1st Method
        // if(pos.find(val)==pos.end())
        //     return 0;
        // pos.erase(val);
        // return 1;
        
        
        //2nd Method
        if(pos.find(val) == pos.end())
            return 0;
        
        int p1 = pos[val];
        int p2 = values.size() - 1;
        
        swap(values[p1], values[p2]);
        pos[values[p1]] = p1;
        pos.erase(val);
        values.pop_back();
        return 1;
    }
    
    int getRandom() {
        //1st Method
        // return next(pos.begin(), rand() % pos.size()) -> first;
        
        
        //2nd Method
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */