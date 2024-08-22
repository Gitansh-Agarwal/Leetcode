class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair <pair<int, int>, int>> q;
        
        //Visiting all Zeros in the matrix and pushing them into the queue.
        //TC=O(N*M).
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        //Traversing the queue.
        int delRow[]={-1, 0, +1, 0};
        int delCol[]={0, +1, 0, -1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int stepsToMove=q.front().second;
            dist[row][col]=stepsToMove;
            q.pop();
            
            for(int i=0; i<4; i++){
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0){
                    vis[newRow][newCol]=1;
                    q.push({{newRow, newCol}, stepsToMove+1});
                }
            }
        }
        return dist;
    }
};