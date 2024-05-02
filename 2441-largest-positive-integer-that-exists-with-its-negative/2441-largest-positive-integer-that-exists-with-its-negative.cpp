class Solution {
public:
    int findMaxK(vector<int>& nums) {
        //TC=O(N^2).
        //Using two loops for traversing the entire array.
        // int n=nums.size();
        // int ans=INT_MIN;
        // for(int i=0; i<n; i++){
        //     if(nums[i]>0){
        //         for(int j=0; j<n; j++){
        //             if(nums[j]==-nums[i]){
        //                 ans=max(ans, nums[i]);
        //                 break;
        //             }
        //         }
        //     }
        // }
        // if(ans==INT_MIN)
        //     return -1;
        // return ans;
        
        
        //TC=O(NlogN+NlogN) = O(NlogN).
        //Sorting the array and then using binary search for each and every positive value starting from the right. 
        //Sorting
        sort(nums.begin(), nums.end());
        
        //Applying binary search
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]<0){
                break;
            }
            
            int x=-nums[i];
            if(binary_search(nums.begin(), nums.begin()+i, x)){
                return nums[i];
            }
        }
        return -1;
    }
};