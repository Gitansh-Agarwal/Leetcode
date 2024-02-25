class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Below method is giving TLE Error.
        int sum;
        int length = nums.size();
        int count=0;
        for(int sp=0; sp<length; sp++){
            
            sum = 0;
            for(int ep=sp; ep<length; ep++){
                
                sum+=nums[ep];
                
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
        
    }
};