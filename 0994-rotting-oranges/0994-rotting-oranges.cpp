class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //n*m
        queue<pair< pair<int, int>, int>> q;
        
        int vis[n][m];
        int cntFresh=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, +1, 0, -1};
        int tmax=0;
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            if(tm>tmax){
                tmax=tm;
            }
            for(int i=0; i<4; i++){
                int nRow= row + drow[i];
                int nCol= col + dcol[i];
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]!=2 && grid[nRow][nCol]==1){
                    q.push({{nRow, nCol}, tm+1});
                    vis[nRow][nCol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh){
            return -1;
        }
        return tmax;
    }
};