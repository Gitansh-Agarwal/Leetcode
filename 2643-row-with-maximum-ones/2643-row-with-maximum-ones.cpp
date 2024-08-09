class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x){
        int low=0;
        int high=n-1;
        int ans=n;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //Using Kind of linear search.
        //TC=O(N*M).
        //SC=O(1).
        
        int n=mat.size();
        int m=mat[0].size();
        int maxOnes=0;
        int maxOnesRowsInd=0;
        for(int i=0; i<n; i++){
            int cntOne=0;
            for(int j=0; j<m; j++){
                // if(mat[i][j]==1)   cntOne++;
                // OR
                cntOne+=mat[i][j];
            }
            if(cntOne>maxOnes){
                maxOnes=cntOne;
                maxOnesRowsInd=i;
            }
        }
        return {maxOnesRowsInd, maxOnes};
        
        
        
        
        //Below Solution will be applicable to matrices having each row as sorted.
        // //TC=O(N* log2(M)).
        // //SC=O(1).
        // int n=mat.size();
        // int m=mat[0].size();
        // int maxOnes=0;
        // int index=-1;
        // for(int i=0; i<n; i++){
        //     int cntOnes= m - lowerBound(mat[i], m, 1);
        //     if(cntOnes>maxOnes){
        //         maxOnes=cntOnes;
        //         index=i;
        //     }
        // }
        // return {index, maxOnes};
    }
};