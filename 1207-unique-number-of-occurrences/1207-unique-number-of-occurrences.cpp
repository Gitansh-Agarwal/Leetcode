class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> st;
        
        for(int i=0; i<arr.size(); i++){
            ++mp[arr[i]];
        }
        
        for(auto i : mp){
            st.insert(i.second);
        }
        
        return mp.size() == st.size();
        
    }
};