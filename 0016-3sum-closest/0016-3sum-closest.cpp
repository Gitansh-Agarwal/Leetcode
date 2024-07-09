class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        //Sorting the given vector nums.
        sort(nums.begin(), nums.end());
        int resultSum=nums[0]+nums[1]+nums[2];
        int minDifference=INT_MAX;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
                
                int diffToTarget=abs(sum-target);
                
                if(diffToTarget<minDifference){
                    minDifference=diffToTarget;
                    resultSum=sum;
                }
            }
        }
        return resultSum;
    }
};