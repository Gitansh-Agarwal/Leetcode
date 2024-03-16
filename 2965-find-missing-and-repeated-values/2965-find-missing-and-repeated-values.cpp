class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //Hashing
        //SC=O(n*n), TC=
//         int n = grid.size();
//         // int n = grid[0].size();
//         int size = n*n;
//         int a,b;
        
//         vector<int> temp(size,0);
//         vector<int> ans;
        
//         for(int i=0; i<n; i++){
            
//             for(int j=0; j<n; j++){
                
//                 temp[grid[i][j]-1]++;
//             }
//         }
        
//         for(int i=0; i<size; i++){
//             if(temp[i] > 1){
//                 a = i + 1;
//             }
//             else if(temp[i] == 0){
//                 b= i + 1;
//             }
//         }
//         ans.push_back(a);
//         ans.push_back(b);
//         return ans;
        
        
        long long n=grid.size()*grid.size();
        long long Sn, S2n;
        Sn = (n*(n+1))/2;
        S2n = (n * (n+1) * (2*n+1))/6;
        
        long long S=0, S2=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                S += grid[i][j];
                S2 += (long long)grid[i][j]*(long long)grid[i][j];
            }
            
        }
        
        long long val1 = S-Sn;//x-y
        long long val2 = S2-S2n;//x^2-y^2
        val2=val2/val1;//x+y
        
        long long x=(val1+val2)/2;
        long long y=x-val1;//or y=val2-x
        
        return {(int)x, (int)y};
    }
};