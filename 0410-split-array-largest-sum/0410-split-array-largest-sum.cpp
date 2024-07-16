class Solution {
public:
    int findNoOfSplits(vector<int>&nums, int sum){
        int noOfSplits=1;
        int total=0;
        
        for(int i=0; i<nums.size(); i++){
            if(total+nums[i] <= sum){
                total+=nums[i];
            }
            else{
                noOfSplits++;
                total=nums[i];
            }
        }
        return noOfSplits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        //below if statement not required.
        if(k>n){
            return -1;
        }
        
        
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        int ans=-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            int splits = findNoOfSplits(nums, mid);
            // if(splits == k){
            //     ans=mid;
            //     high=mid-1;
            // }
            // else if(splits > k){
            //     low=mid+1;
            // }
            // else{
            //     high=mid-1;
            // }
            
            //OR
            if(splits > k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        // return ans;
         return low;
    }
};