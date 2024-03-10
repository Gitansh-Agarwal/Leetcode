class Solution {
    private:
        void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int initialColor, int newColor, int delRow[], int delCol[]){
            ans[row][col]=newColor;
            
            int n=image.size();
            int m=image[0].size();
            for(int i=0; i<4; i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow ][ ncol]!=newColor){
                    dfs(nrow, ncol, image, ans, initialColor, newColor, delRow, delCol);
                }
            }
        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Using BFS
        //TC=O(N*M) + O(N*M*4) = O(N*M) as in worst case every node will be a part of queue i.e.every node will be traversed
        //SC=O(N*M) {queue size at max = O(N*M) + external ans matrix O(N*M) for storing the answer}
//         int n=image.size();
//         int m=image[0].size();
        
//         queue<pair<int, int>> q;
//         vector<vector<int>> ans=image;
//         int initialValue=image[sr][sc];
//         q.push({sr,sc});
        
//         int drow[]={-1, 0, +1, 0};
//         int dcol[]={0, +1, 0, -1};
//         while(!q.empty()){
//             int r=q.front().first;
//             int c=q.front().second;
            
//             ans[r][c]=color;
//             q.pop();
//             for(int i=0; i<4; i++){
//                 int nrow=r+drow[i];
//                 int ncol=c+dcol[i];
                
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==initialValue){
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//         return ans;
        
        
        
        
        
        //Using DFS
        // TC=O(N*M) as for X nodes, x dfs calls are made + for each of X nodes loop runs for 4 times
        // which is X+X*4 = O(X) = O(N*M).
        // SC=O(N*M){for storing the answer in ans matrix}+O(N*M){Recursion Stack Space}.
        
        //getting initial color
        int initialColor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        //delta row and delta column for 4-directional neighbours
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        dfs(sr, sc, image, ans, initialColor, color, delRow, delCol);
        
        return ans;
    }
};