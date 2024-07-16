class Solution {
public:
     int findNoOfStores(vector<int>&quantities, int products){
         int noOfStores=0;
        for(int i=0; i<quantities.size();i++){
            noOfStores+=ceil((double)quantities[i]/(double)products);
        }
        
        return noOfStores;
        
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // long long int total=accumulate(quantities.begin(), quantities.end(), 0);
         int low=1;
         int high=*max_element(quantities.begin(), quantities.end());
         int ans=-1;
        
        while(low<=high){
             int mid=(low+high)/2;
             int stores=findNoOfStores(quantities, mid);
            
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