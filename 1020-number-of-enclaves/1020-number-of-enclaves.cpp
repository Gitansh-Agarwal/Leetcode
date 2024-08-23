class Solution {
    private:
        void dfs(int m, int n, int row, int col, int& cnt, vector<vector<int>>&grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
            vis[row][col]=1;
            cnt++;
            
            for(int i=0; i<4; i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol]==1 && !vis[nRow][nCol]){
                    dfs(m, n, nRow, nCol, cnt, grid, vis, delRow, delCol);
                }
            }
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //Marking all 1's cells which are somehow connected to the boundary.
        int m=grid.size();
        int n=grid[0].size();
        int cnt1ConnectedToBoundary=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        
        //Traversing through 1st and last row
        for(int j=0; j<n; j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(m, n, 0, j, cnt1ConnectedToBoundary, grid, vis, delRow, delCol);
            }
            
            if(grid[m-1][j]==1 && !vis[m-1][j]){
                dfs(m, n, m-1, j, cnt1ConnectedToBoundary, grid, vis, delRow, delCol);
            }
        }
        
        //Traversing through remaining elements of first and last columns.
        for(int i=0; i<m-1; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(m, n, i, 0, cnt1ConnectedToBoundary, grid, vis, delRow, delCol);
            }
            
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(m, n, i, n-1, cnt1ConnectedToBoundary, grid, vis, delRow, delCol);
            }
        }
        
        
        int TotalNumberOfOnes=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    TotalNumberOfOnes++;
                }
            }
        }
        return TotalNumberOfOnes-cnt1ConnectedToBoundary;
    }
};