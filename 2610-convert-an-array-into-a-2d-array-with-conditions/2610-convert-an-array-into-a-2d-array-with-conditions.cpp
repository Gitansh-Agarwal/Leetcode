class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(auto i : nums){
            ++freq[i];
        }
        
        int size = 0;//Here size is minimum number of rows required in the 2d vector.
        for(auto i : freq){
            size = max(size, i.second);
        }
        
        vector<vector<int>> ans(size);
        
        for(auto i : freq){
            for(int j=0; j<i.second; j++)
                ans[j].push_back(i.first);
        }
        
        return ans;
    }
};