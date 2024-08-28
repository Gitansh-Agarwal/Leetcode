class Solution {
private:
    void dfs(vector<vector<int>>& tempGrid1, vector<vector<int>>& tempGrid2, int i, int j,
            int& flag, int n, int m, int delRow[], int delCol[]){
        
        if(tempGrid1[i][j]==0){
            flag=0;
            return;
        }
        tempGrid2[i][j]=0;
        
        for(int k=0; k<4; k++){
            int nRow=i+delRow[k];
            int nCol=j+delCol[k];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && tempGrid2[nRow][nCol]==1){
                dfs(tempGrid1, tempGrid2, nRow, nCol, flag, n, m, delRow, delCol);
                
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> tempGrid1=grid1;
        vector<vector<int>> tempGrid2=grid2;
        // for(int i=0; i<tempGrid1.size(); i++){
        //     for(int j=0; j<tempGrid1[0].size(); j++){
        //         cout<<tempGrid1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int n=grid2.size();
        int m=grid2[0].size();
        int cnt=0;
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int flag=1;
                if(tempGrid2[i][j]==1){
                    dfs(tempGrid1, tempGrid2, i, j, flag, n, m, delRow, delCol);
                    if(flag==1)
                    cnt++; 
                }
                
                
            }
        }
        return cnt;
    }
};