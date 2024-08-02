class Solution {
public:
    
    int LCS(string x, string y, int m, int n, vector<vector<int>>&t){
        if(m==0 || n==0){
            return 0;
        }
        
        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(x[m-1] == y[n-1]){
            return t[m][n]=1+LCS(x,y, m-1, n-1, t);
        }
        else {
            return t[m][n]=max(LCS(x,y, m-1, n, t) , LCS(x,y, m, n-1, t));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         int dp[n + 1][m + 1];

//         for(int i = 0; i < m + 1; i++)
//             dp[n][i] = 0;
//         for(int i = 0; i < n + 1; i++)
//             dp[i][m] = 0;

//         for(int i = n - 1; i > -1; i--){
//             for(int j = m - 1; j > -1; j--){
//                 if(text1[i] == text2[j]){
//                     dp[i][j] = 1 + dp[i + 1][j + 1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
//                 }
//             }
//         }

//         return dp[0][0];
        
        
        
        //Recursive CODE
        // return LCS(text1, text2,text1.size(), text2.size());
        
        
        //Memoization
//         int m=text1.size(), n=text2.size();
//          vector<vector<int>> t(m+1, vector<int>(n+1,-1));
        
//         return LCS(text1, text2,text1.size(), text2.size(), t);
        
        
        //Top-Down Approach.
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1,0));
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];

    }
};