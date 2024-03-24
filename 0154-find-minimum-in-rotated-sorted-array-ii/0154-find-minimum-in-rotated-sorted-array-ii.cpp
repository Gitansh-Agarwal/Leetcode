class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){
                ans=min(ans, nums[low]);
                low=low+1;
                high=high-1;
                continue;
            }
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