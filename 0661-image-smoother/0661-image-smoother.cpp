class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        
        //           U , D , L , R , UL , UR , DL, DR
        int dx[] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1};
        int dy[] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1};
        
        vector<vector<int>> ans(m , vector<int>(n));
        int nx,ny;
        int sum;
        int count;
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                sum = img[i][j];
                count =1;
                
                for(int k=0; k<8; k++){
                    
                    nx = i + dx[k];
                    ny = j + dy[k];
                    
                    if(!(nx<0 or nx>=m or ny<0 or ny>=n)){
                        
                        sum+=img[nx][ny];
                        count++;
                    }
                }
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};