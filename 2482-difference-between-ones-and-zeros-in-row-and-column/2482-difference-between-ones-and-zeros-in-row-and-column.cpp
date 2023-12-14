class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> row(m,0) , column(n,0);
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                // row[i]+=grid[i][j];
                // column[j]+=grid[i][j];
                
                if(grid[i][j] == 1){
                    row[i]++;
                    column[j]++;
                }
                
            }
        }
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                grid[i][j] = 2*(row[i] + column[j]) - (m + n);
                
            }
        }
        
        return grid;
    }
};