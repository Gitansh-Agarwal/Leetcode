class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> mp;
        
        for(auto i : paths){
            mp[i[1]] = 1;
        }
        for(auto i : paths){
            mp.erase(i[0]);
        }
        return (*mp.begin()).first;
    }
};