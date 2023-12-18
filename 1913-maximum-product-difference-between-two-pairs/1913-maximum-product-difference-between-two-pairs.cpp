class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maximum = INT_MIN;
        int secondMaximum = INT_MIN;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        int length = nums.size();
        
        for(int i=0; i<length; i++){
            
            //Finding the smallest and second smallest value in the array.
            
            if(nums[i] < smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < secondSmallest){
                secondSmallest = nums[i];
            }
            
            //Finding the maximum and second maximum value in the array.
            if(nums[i] > maximum){
                secondMaximum = maximum;
                maximum = nums[i];
            }
            else if(nums[i] > secondMaximum){
                secondMaximum = nums[i];
            }
        }
        
        return ((maximum * secondMaximum) - (smallest * secondSmallest));
    }
};