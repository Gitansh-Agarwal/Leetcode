class Solution {
public:
    bool binarySearch(vector<int> arr, int m, int target){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]==target)
                return true;
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //TC=O(n*m).
        //SC=O(1).
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j]==target){
//                     return true;
//                 }
//             }
//         }
//         return false;
        
        
        //TC=O(n + log2(m)).
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                return binarySearch(matrix[i], m, target);
            }
        }
        return false;
    }
};