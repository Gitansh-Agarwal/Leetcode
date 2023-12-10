class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
//         The below code is giving TLE error as it has a time complexity of O(N^3) approximately
//         int sum;
//         int max_sum=INT32_MIN;
//         int length = nums.size();
//         for(int sp=0; sp<length; sp++){
            
//             for(int ep=sp; ep<length; ep++){
                
//                 sum=0;
//                 for(int i=sp; i<=ep; i++){
//                     sum+=nums[i];
//                 }
//                 if(sum > max_sum){
//                     max_sum = sum;
//                 }
//             }
//         }
//         return max_sum;
        
        
        // Using O(N^2) time Complexity i.e. in the above code not using the third for loop. This approach is also giving TLE Error as the question is demanding an O(N) time complexity solution.
//         int sum;
//         int max_sum=INT32_MIN;
//         int length = nums.size();
//         for(int sp=0; sp<length; sp++){
            
//             sum=0;
//             for(int ep=sp; ep<length; ep++){
//                 sum+=nums[ep];
                
                
//                 if(sum > max_sum){
//                     max_sum = sum;
//                 }
//             }
//         }
//         return max_sum;
        
        
        //Using Kadane's Algorithm Time Complexity = O(N) and Space Complexity = O(1).
        
        int sum = 0;
        int max_sum = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            
            sum+=nums[i];
            if(sum > max_sum){
                max_sum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return max_sum;
        
    }
};