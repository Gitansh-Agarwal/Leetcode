class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            long long prod=1;
            for(int j=i; j<n; j++){
                prod*=nums[j];
                if(prod<(long long)k){
                    count++;
                }
                else if(prod>=(long long)k){
                    break;
                }
            }
        }
        return count;
    }
};