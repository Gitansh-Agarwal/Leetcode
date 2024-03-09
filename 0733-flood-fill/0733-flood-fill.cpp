class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> ans=image;
        int initialValue=image[sr][sc];
        q.push({sr,sc});
        
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, +1, 0, -1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            
            ans[r][c]=color;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==initialValue){
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};