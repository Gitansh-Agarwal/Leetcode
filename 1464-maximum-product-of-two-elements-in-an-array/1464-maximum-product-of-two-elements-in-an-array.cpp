class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
//         finding the maximum and the second maximum value by using two for loops so as to find the result 
//         int length = nums.size();
//         int max1 = INT_MIN;
//         int max2 = INT_MIN;
//         int index;
//         for(int i=0; i<length; i++){
            
//             if(nums[i] > max1){
                
//                 max1 = nums[i];
//                 index = i;
//             }
//         }
        
//         for(int i=0; i<length; i++){
            
//             if(nums[i] > max2 and i!=index){
                
//                 max2 = nums[i];
//             }
//         }
        
//         return (max1-1)*(max2-1);
        
        
        // Another method to find the maximum and second maximum value but using only a single for loop so as to find the result.
        
        int firstMax = 0;
        int secondMax = 0;
        
        // Using for each loop 
        for(auto x : nums){
            
            if(x > firstMax){
                
                secondMax = firstMax;
                firstMax = x;
            }
            else if(x > secondMax){
                
                secondMax = x;
            }
        }
        
        return (firstMax-1)*(secondMax-1);
        
    }
};