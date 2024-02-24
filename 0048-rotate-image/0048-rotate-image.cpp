class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute Force Solution
        //TC=O(N^2), extra SC=O(N^2).
        int n= matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};