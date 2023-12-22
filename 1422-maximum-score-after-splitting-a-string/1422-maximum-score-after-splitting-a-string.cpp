class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> suffix(n,0);
        
        suffix[n-1] = (s[n-1] == '1');
        int ans = 0;
        int zerosTillCurrentIndex = 0;
        
        for(int i=n-2; i>0; i--){
            suffix[i] = suffix[i+1] + (s[i] == '1');
        }
        
        for(int i=0; i<n-1; i++){
            zerosTillCurrentIndex += (s[i] == '0');
            
            ans = max(ans , zerosTillCurrentIndex + suffix[i+1]);
        }
        
        return ans;
    }
};