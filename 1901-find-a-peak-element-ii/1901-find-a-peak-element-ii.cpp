class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int diffI[] = {-1, 0, +1, 0};
        int diffJ[] = {0, +1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int temp=1;
                for(int k=0; k<4; k++){
                    int newI=i+diffI[k];
                    int newJ=j+diffJ[k];
                    
                    int val = ((newI>=0 && newI<n) && (newJ>=0 && newJ<m))? mat[newI][newJ]:-1;
                    if(mat[i][j]<=val){
                        temp=0;
                        break;
                    }
                }
                if(temp==1){
                    return {i, j};
                }
            }
        }
        return {-1,-1};
    }
};