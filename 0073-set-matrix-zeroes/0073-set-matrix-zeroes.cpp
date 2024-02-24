class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Better Solution
        //TC=O(2*m*n) + O(m)+O(n), extra SC=O(m)+O(n).
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int row[m];
//         int col[n];
//         int i,j;
//         for(i=0;i<m;i++){
//             row[i]=0;
//         }
//         for(j=0;j<n;j++){
//             col[j]=0;
//         }
        
//         for(i=0;i<m;i++){
//             for(j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=1;
//                     col[j]=1;
//                 }
                
//             }
//         }
//         for(i=0;i<m;i++){
//             for(j=0;j<n;j++){
//                 if(row[i]==1 || col[j]==1){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
        
        
        

        //Optimal Solution
        //Tc=O(2*m*n), extra SC=O(1).
        int m=matrix.size();
        int n=matrix[0].size();
        //int col[n] = 0; -> matrix[0][..]
        //int row[m] = 0; -> matrix[..][0]
        
        int col0=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    // mark the ith row
                    matrix[i][0] = 0;
                    // mark the jth column
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                // check the ith row and jth column
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};