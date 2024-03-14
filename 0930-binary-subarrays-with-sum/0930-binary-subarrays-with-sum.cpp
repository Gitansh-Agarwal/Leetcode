class Solution {
public:
    int atmostK(vector<int>& nums, int goal){
        int sum=0;
        int ans=0; 
        int start=0;
        for(int end=0; end<nums.size(); end++){
            sum+=nums[end];
            while(sum>goal && start<=end){
                sum-=nums[start];
                start++;
            }
            ans+=(end-start+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostK(nums, goal)-atmostK(nums, goal-1);
    }
};