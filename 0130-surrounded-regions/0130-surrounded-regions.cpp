class Solution {
public:
    void dfs(int m, int n, int row, int col, vector<vector<char>>&board, vector<vector<int>>&vis, int delRow[], int delCol[]){
        vis[row][col]=1;
        
        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n){
                if(board[nRow][nCol]=='O' && vis[nRow][nCol]==0){
                    dfs(m, n, nRow, nCol, board, vis, delRow, delCol);
                }
            }
            
        } 
    }
    void dfs2(int m, int n, int row, int col, vector<vector<char>>&board, vector<vector<int>>&vis, vector<vector<char>>&ans, int delRow[], int delCol[]){
        ans[row][col]='O';
        vis[row][col]=1;
        
        for(int i=0; i<4; i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n){
                if(board[nRow][nCol]=='O' && vis[nRow][nCol]==0){
                    dfs2(m, n, nRow, nCol, board, vis, ans, delRow, delCol);
                }
            }
            
        } 
    }
    void solve(vector<vector<char>>& board) {
        //TC=O(2m+2n) + O(dfs traversal)
//         int m=board.size();
//         int n=board[0].size();
//         vector<vector<int>> vis(m, vector<int>(n, 0));
//         int delRow[]={-1, 0, +1, 0};
//         int delCol[]={0, +1, 0, -1};
//         //Traversing through 1st row.
//         for(int i=0; i<n; i++){
//             if(board[0][i]=='O'){
//                 dfs(m, n, 0, i, board, vis, delRow, delCol);
//             }
//         }
//         //Traversing through last row.
//         for(int i=0; i<n; i++){
//             if(board[m-1][i]=='O'){
//                 dfs(m, n, m-1, i, board, vis, delRow, delCol);
//             }
//         }
//         //Traversing through 1st column.
//         for(int i=1; i<m-1; i++){
//             if(board[i][0]=='O'){
//                 dfs(m, n, i, 0, board, vis, delRow, delCol);
//             }
//         }
//         //Traversing through last column.
//         for(int i=1; i<m-1; i++){
//             if(board[i][n-1]=='O'){
//                 dfs(m, n, i, n-1, board, vis, delRow, delCol);
//             }
//         }
        
        
        
//         //Travesing the entire matrix board and making all the O's which are unvisited as X's.
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(board[i][j]=='O' && vis[i][j]==0){
//                     board[i][j]='X';
//                 }
//             }
//         }
        
        
        
        int m=board.size();
        int n=board[0].size();
        vector<vector<char>> ans(m, vector<char>(n, 'X'));
        vector<vector<int>> vis(m, vector<int>(n, 0));
         int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        //Traversing through 1st row.
        for(int i=0; i<n; i++){
            if(board[0][i]=='O'){
                dfs2(m, n, 0, i, board, vis, ans, delRow, delCol);
            }
        }
        //Traversing through last row.
        for(int i=0; i<n; i++){
            if(board[m-1][i]=='O'){
                dfs2(m, n, m-1, i, board, vis, ans, delRow, delCol);
            }
        }
        //Traversing through 1st column.
        for(int i=1; i<m-1; i++){
            if(board[i][0]=='O'){
                dfs2(m, n, i, 0, board, vis, ans, delRow, delCol);
            }
        }
        //Traversing through last column.
        for(int i=1; i<m-1; i++){
            if(board[i][n-1]=='O'){
                dfs2(m, n, i, n-1, board, vis, ans, delRow, delCol);
            }
        }
        board=ans;
    }
};