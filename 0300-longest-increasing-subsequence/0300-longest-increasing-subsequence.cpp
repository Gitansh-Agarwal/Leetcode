class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1e5);
        
        for(int i=0; i<n; i++){
            int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            
            if(pos<n){
                // dp[pos] = min(dp[pos], nums[i]);
                dp[pos] = nums[i];
            }
        }
        
        for(int i=n-1; i>-1; i--){
            if(dp[i] < 1e5)
                return i+1;
        }
        return 1;
    }
};