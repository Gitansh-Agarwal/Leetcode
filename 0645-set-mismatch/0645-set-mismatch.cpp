class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(),nums.end());
        vector<int> temp(maxValue+1, 0);
        vector<int> ans(2,0);
        
        for(auto i:nums){
            ++temp[i];
        }
        for(int i=1; i<maxValue+1; i++){
            if(temp[i]==0)
                ans[1] = i;
            else if(temp[i]==2)
                ans[0] = i;
        }
        if(ans[1] == 0)
            ans[1] = maxValue+1;
        return ans;
    }
};