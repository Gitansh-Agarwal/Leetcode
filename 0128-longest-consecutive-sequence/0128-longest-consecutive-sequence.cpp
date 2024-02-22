class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int maxLength=0;
        int length=1;
        int n=nums.size();
        if(n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] - nums[i-1] == 1){
                length++;
            }
            else{
                maxLength = max(maxLength, length);
                length=1;
            }
        }
        maxLength = max(maxLength, length);
        return maxLength;
    }
};