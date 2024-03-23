class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;
            
            //search space is already sorted, then nums[low] will always be the smallest in that search space
            if(nums[low]<=nums[high]){
                ans=min(ans, nums[low]);
                break;
            }
            
            //otherwise either one of the left or right half is sorted.
            //left half is sorted
            if(nums[low]<=nums[mid]){
                ans=min(ans, nums[low]);
                low=mid+1;
            }            
            //right half is sorted
            else{
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};