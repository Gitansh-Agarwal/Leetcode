class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute Force Solution
        //But the below method allocates a 2d answer matrix which is wrong wrt to the question.
        //TC=O(N^2), extra SC=O(N^2).
        // int n= matrix.size();
        // vector<vector<int>> ans(n, vector<int>(n));
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         ans[j][n-1-i] = matrix[i][j];
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         matrix[i][j] = ans[i][j];
        //     }
        // }
        
        
        //Optimal Solution
        //TC=O(N/2 * N/2){transpose} + O(N * N/2){reverse matrix rows}.
        //Transpose Matrix = TC=O(N/2 * N/2){transpose}.
        int n= matrix.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //Reverse Transposed Matrix Rows = TC=O(N * N/2){reverse matrix rows}.
        for(int i=0; i<n; i++){
            // row is matrix[i]
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};