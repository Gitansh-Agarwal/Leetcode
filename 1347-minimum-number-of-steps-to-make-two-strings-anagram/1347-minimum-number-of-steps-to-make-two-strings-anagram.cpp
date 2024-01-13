class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        
        for(auto i : s){
            ++freq[i - 'a'];
        }
        for(auto i : t){
            --freq[i - 'a'];
        }
        
        int ans = 0;
        for(int i=0; i<26; i++){
            // ans += abs(freq[i]);
            // ans += freq[i] > 0? freq[i] : 0;
            ans += freq[i] < 0? -freq[i] : 0;
        }
        
        // return ans >> 1;//right shift by 1 means divide by 2;
        return ans;
    }
};