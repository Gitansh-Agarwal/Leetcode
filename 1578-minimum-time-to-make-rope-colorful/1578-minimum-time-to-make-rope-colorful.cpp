class Solution {
public:
    
    //Below solution takes O(N) time and O(1) space.
//     int minCost(string colors, vector<int>& neededTime) {
//         int minTime = 0;
//         int prev = 0;
//         for(int i=1; colors[i]!='\0'; i++){
//             if(colors[i]==colors[prev]){
//                 if(neededTime[prev]<neededTime[i]){
//                     minTime+=neededTime[prev];
//                     prev=i;
//                 }
//                 else{
//                     minTime+=neededTime[i];
//                 }
                
//             }
//             else{
//                 prev=i;
//             }
//         }
//         return minTime;
//     }
    
    
    // OR
    
    //Below solution takes O(N) time and O(1) space.
    //  int minCost(string colors, vector<int>& neededTime) {
    //     int ans = 0;
    //     int prev = 0;
    //     for(int i=1; colors[i]!='\0'; i++){
    //         if(colors[i]!=colors[prev]){
    //             prev=i;
    //         }
    //         else{
    //             if(neededTime[prev]<neededTime[i]){
    //                 ans+=neededTime[prev];
    //                 prev=i;
    //             }
    //             else{
    //                 ans+=neededTime[i];
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    
    //using Dynamic Programming
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>> dp(n+1, vector<int>(27,0));

        //Below i represents the ith indexed balloon and j represents the color of previous balloon.
        for(int i=n-1; i>-1; i--){
            for(int j=0; j<27; j++){
                int remove, noremove;

                remove = neededTime[i] + dp[i+1][j];
                noremove = dp[i+1][colors[i] - 'a' + 1];

                if((colors[i]-'a'+1) == j){
                    dp[i][j] = remove;
                }
                else{
                    dp[i][j] = min(remove, noremove);
                }
            }
        }

        return dp[0][0];

    }
};