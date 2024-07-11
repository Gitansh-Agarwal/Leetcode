class Solution {
public:
    int isPossible(vector<int>& bloomDay, int n, long long int day, int m, int k){
        int noOfBouquets=0;
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                noOfBouquets+=(cnt/k);
                cnt=0;
            }
        }
        noOfBouquets+=(cnt/k);
        if(noOfBouquets >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=bloomDay.size();
        
        for(int i=0; i<n; i++){
            if(bloomDay[i]<mini){
                mini=bloomDay[i];
            }
            
            if(bloomDay[i]>maxi){
                maxi=bloomDay[i];
            }
        }
        
        
        //answer will lie in the range of (mini-maxi).
        //using linear Search -> It is giving TLE Error.
        //TC=O((maxi-mini+1)* n)
        
        
//         for(int i=mini; i<=maxi; i++){
//             if(isPossible(bloomDay, n, i, m, k) == true){
//                 return i;
//             }
//         }
        
//         // else --> (m*k > n)
//         return -1;
        
        
        
        
        //Using Binary Search
        // TC=O(log(maxi-mini+1)*n)
        
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(isPossible(bloomDay, n, mid, m, k) == true){
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