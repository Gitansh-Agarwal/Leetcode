class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int n=nums.size();
        // int low=0;
        // int high=n-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(nums[mid] == target){
        //         return mid;
        //     }
        //     else if(nums[mid] < target){
        //         low=mid+1;
        //     }
        //     else{
        //         high=mid-1;
        //     }
        // }
        // return low;
        
        //We are simply asked to find out the lower bound of the given value.
        //Correct Answer= Using Lower Bound
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(nums[mid] >= target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};