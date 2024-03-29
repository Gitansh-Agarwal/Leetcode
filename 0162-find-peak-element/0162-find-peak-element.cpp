class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //trying out linear search
        //TC=O(N).
        // int n=nums.size();
        // // int peakElement;
        // if(n==1){
        //     return 0;
        // } 
        // int i;
        // for(i=0; i<n; i++){
        //     if(i==0){
        //         if(nums[i]>nums[i+1]){
        //             // return i;
        //             break;
        //         }
        //     }
        //     else if(i==n-1){
        //         if(nums[i]>nums[i-1]){
        //             // return i;
        //             break;
        //         }
        //     }
        //     else{
        //         if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
        //             // return i;
        //             break;
        //         }
        //     }
        // }
        // return i;
        
        
        
        //Using Binary Search
        //TC=O(logN).
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }
            else{
                low=mid+1;
                // or
                // high=mid-1;
            }
        }
        return -1;
    }
};