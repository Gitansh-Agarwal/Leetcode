class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n=nums.size();
        int req=n/3+1;
        for(auto it: nums){
            if(mpp[it] == req-1)
                ans.push_back(it);
            mpp[it]++;
        }
        // for(auto it: mpp){
        //     if(it.second > (nums.size()/3))
        //         ans.push_back(it.first);
        // }
        return ans;
    }
};