class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Below method is working now somehow and is not giving TLE Error.
//         int sum;
//         int length = nums.size();
//         int count=0;
//         for(int sp=0; sp<length; sp++){
            
//             sum = 0;
//             for(int ep=sp; ep<length; ep++){
                
//                 sum+=nums[ep];
                
//                 if(sum == k){
//                     count++;
//                 }
//             }
//         }
//         return count;
        
        
        
        //Optimal Solution = Using Prefix Sum
        //TC=O(N * logN){ordered map} or O(N){unordered map} 
        //Extra SC=O(N).
        int cnt=0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum=0;
        for(int i=0; i<nums.size(); i++){
            prefixSum+=nums[i];
            int remove = prefixSum - k;
            cnt+=mpp[remove];
            mpp[prefixSum]+=1;
        }
        return cnt;
    }
};