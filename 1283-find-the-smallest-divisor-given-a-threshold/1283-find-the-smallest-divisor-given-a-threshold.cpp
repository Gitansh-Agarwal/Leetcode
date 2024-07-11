class Solution {
public:
    int divResult(vector<int>&nums, int n, int divisor){
        int res=0;
        for(int i=0; i<n; i++){
            res+=ceil((double)nums[i]/(double)divisor);
        }
        return res;
    }
    void find(vector<int>&nums, int n, pair<int, int>& maxMin){
        for(int i=0; i<n; i++){
            if(nums[i]<maxMin.first){
                maxMin.first=nums[i];
            }
            
            if(nums[i]>maxMin.second){
                maxMin.second=nums[i];
            }
        }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        pair<int, int> maxMin;
        maxMin.first=INT_MAX;//mini
        maxMin.second=INT_MIN;//maxi
        int n=nums.size();
        
        find(nums, n, maxMin);
        
        
        if(n==threshold){
            return maxMin.second;//returning maxi
        }
        // int low=maxMin.first;
        int low=1;
        int high=maxMin.second;
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(divResult(nums, n, mid) <= threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};