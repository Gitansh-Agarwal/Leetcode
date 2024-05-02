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
//         sort(nums.begin(), nums.end());
        
//         //Applying binary search
//         for(int i=nums.size()-1; i>0; i--){
//             if(nums[i]<0){
//                 break;
//             }
            
//             int x=-nums[i];
//             if(binary_search(nums.begin(), nums.begin()+i, x)){
//                 return nums[i];
//             }
//         }
//         return -1;
        
        
        
        //TC=O(NlogN + N) = O(NlogN).
        //Sorting the array and then using two pointer approach.
        //Sorting
        sort(nums.begin(), nums.end());
        
        //Using two pointer approach.
        int right=nums.size()-1;
        int left=0;
        while(left<right){
            if(nums[right]<0)
                break;
            
            if(abs(nums[left]) < nums[right]){
                right--;
            }
            else if(abs(nums[left]) > nums[right]){
                left++;
            }
            //checking if the values have opposite signs
            else if(-nums[left] == nums[right]){
                return nums[right];
            }
            //it means that the values have same sign which means there is no largest positive integer k such that -k also exists in the array.
            else{
                break;
            }
        }
        return -1;
    }
};