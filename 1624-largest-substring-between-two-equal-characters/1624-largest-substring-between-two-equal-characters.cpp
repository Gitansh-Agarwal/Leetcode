class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> freq(26, {-1, -1});
        int n = s.size();
        
        //we are just finding the minimum and maximum index at which a particular character occurs.
        for(int i=0; i<n; i++){
            freq[s[i]-'a'][1] = i;//storing the maximum index at position(column) index 1
            freq[s[n-i-1] - 'a'][0] = n-i-1;//storing the minimum index at column 0;
        }
        
        int ans = -1;
        for(int i=0; i<26; i++){
            if(freq[i][0] != -1){
                ans = max(ans, freq[i][1] - freq[i][0] - 1);
            }
        }
        return ans;
    }
};