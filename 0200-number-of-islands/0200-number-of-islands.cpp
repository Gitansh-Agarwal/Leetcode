class Solution {
private:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid, 
             vector<vector<int>>& vis, int delRow[], int delCol[]){
        
        vis[row][col]=1;
        
        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
               && grid[nRow][nCol]=='1' && !vis[nRow][nCol]){
                dfs(nRow, nCol, n, m, grid, vis, delRow, delCol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i, j, n, m, grid, vis, delRow, delCol);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};