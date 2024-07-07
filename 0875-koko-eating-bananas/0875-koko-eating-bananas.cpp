class Solution {
public:
    int maxElement(vector<int> &piles, int n){
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi, piles[i]);
        }
        return maxi;
    }
    long long int findHrs(vector<int> &piles, int n, int mid){
        long long int totalHrs = 0;
        for(int i=0; i<n; i++){
            totalHrs+=ceil(double(piles[i])/double(mid));
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=maxElement(piles,n);
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            long long int totalHrs = findHrs(piles, n,  mid);
            
            if(totalHrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};