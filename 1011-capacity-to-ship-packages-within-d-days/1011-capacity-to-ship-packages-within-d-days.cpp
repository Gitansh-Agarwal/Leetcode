class Solution {
public:
    int reqNoOfDays(vector<int>& weights, int n, int capacity){
        // int noOfDays=0;
        // int capacity=mid;
        // int i=0;
        // while(i<n){
        //     if(weights[i]<=capacity){
        //         capacity-=weights[i];
        //         i++;
        //     }
        //     else{
        //         noOfDays++;
        //         capacity=mid;
        //     }
        // }
        // if(capacity!=mid){
        //     noOfDays++;
        // }
        // return noOfDays;
        int reqDays=1;
        int load=0;
        
        for(int i=0; i<n; i++){
            if(load+weights[i] > capacity){
                reqDays++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return reqDays;
    }
    void findMax(vector<int>&weights, int n, int& maxi, int& sum){
        for(int i=0; i<n; i++){
            if(weights[i]>maxi){
                maxi=weights[i];
            }
            sum+=weights[i];
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        int maxi=INT_MIN;
        int sum=0;
        findMax(weights, n, maxi, sum);
        int low=maxi;
        int high=sum;
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
                if(reqNoOfDays(weights, n, mid) <= days){
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