class Solution {
public:
    long long int findNoOfStores(vector<int>&quantities, int products){
        long long int noOfStores=0;
        for(int i=0; i<quantities.size();i++){
            noOfStores+=ceil((double)quantities[i]/(double)products);
        }
        
        return noOfStores;
        
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // long long int total=accumulate(quantities.begin(), quantities.end(), 0);
        long long int low=1;
        long long int high=*max_element(quantities.begin(), quantities.end());
        long long int ans=-1;
        
        while(low<=high){
            long long int mid=(low+high)/2;
            long long int stores=findNoOfStores(quantities, mid);
            
            if(stores > n){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
        //OR
        //return low;
    }
};