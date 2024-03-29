class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //trying out linear search
        //TC=O(N).
        int n=nums.size();
        // int peakElement;
        if(n==1){
            return 0;
        } 
        int i;
        for(i=0; i<n; i++){
            if(i==0){
                if(nums[i]>nums[i+1]){
                    // return i;
                    break;
                }
            }
            else if(i==n-1){
                if(nums[i]>nums[i-1]){
                    // return i;
                    break;
                }
            }
            else{
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                    // return i;
                    break;
                }
            }
        }
        return i;
        
    }
};