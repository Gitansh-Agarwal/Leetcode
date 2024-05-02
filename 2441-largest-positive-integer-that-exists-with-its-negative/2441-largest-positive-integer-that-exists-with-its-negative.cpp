class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // map<int, int> mpp;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                for(int j=0; j<n; j++){
                    if(nums[j]==-nums[i]){
                        ans=max(ans, nums[i]);
                        break;
                    }
                }
            }
        }
        if(ans==INT_MIN)
            return -1;
        return ans;
    }
};