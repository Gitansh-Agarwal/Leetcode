class Solution {
public:
    int maxElement(vector<vector<int>> &mat, int n, int mid){
        int maxi=0;
        int rowInd=-1;
        for(int i=0; i<n; i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                rowInd=i;
            }
        }
        return rowInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         int diffI[] = {-1, 0, +1, 0};
//         int diffJ[] = {0, +1, 0, -1};
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 int temp=1;
//                 for(int k=0; k<4; k++){
//                     int newI=i+diffI[k];
//                     int newJ=j+diffJ[k];
                    
//                     int val = ((newI>=0 && newI<n) && (newJ>=0 && newJ<m))? mat[newI][newJ]:-1;
//                     if(mat[i][j]<=val){
//                         temp=0;
//                         break;
//                     }
//                 }
//                 if(temp==1){
//                     return {i, j};
//                 }
//             }
//         }
//         return {-1,-1};
        
        
        
        //Using Binary Search.
        //TC=O(log2(m) * n).
        //SC=O(1).
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high=m-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            //Here row denotes the row no. of the maximum element present in the column 'mid'.
            int row=maxElement(mat, n, mid);
            int left= mid-1>=0? mat[row][mid-1] : -1;
            int right= mid+1<m? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row, mid};
            }
            else if(mat[row][mid]<left){
                high=mid-1;
            }
            else {//means mat[row][mid]<right
                low=mid+1;
            }
        }
        return {-1, -1};//dummy return statement so that code can be successfully compiled and executed.
    }
};