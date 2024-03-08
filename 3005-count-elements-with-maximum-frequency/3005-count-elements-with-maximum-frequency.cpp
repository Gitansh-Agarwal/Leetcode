class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b){
        return a.second>b.second;
    }
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), compare);
        // int maxFreq=(*(v.begin())).second;
        int maxFreq=v.begin()->second;
        int ans=0;
        for(auto it: v){
            if(it.second==maxFreq)
                ans+=it.second;
            else
                break;
        }
        return ans;
    }
};