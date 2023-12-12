class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
        int length = nums.size();
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int index;
        for(int i=0; i<length; i++){
            
            if(nums[i] > max1){
                
                max1 = nums[i];
                index = i;
            }
        }
        
        for(int i=0; i<length; i++){
            
            if(nums[i] > max2 and i!=index){
                
                max2 = nums[i];
            }
        }
        
        return (max1-1)*(max2-1);
    }
};