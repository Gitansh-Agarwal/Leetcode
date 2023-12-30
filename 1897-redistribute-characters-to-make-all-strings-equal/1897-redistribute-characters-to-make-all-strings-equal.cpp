class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //Initializing the vector freq of size 26 with value (0).
        vector<int> freq(26, 0);
        
        for(auto i : words){
            for(auto j : i){
                ++freq[j-'a'];
            }
        }
        
        bool ok = 1;
        int length = words.size();
        for(int i=0; i<26; i++){
            ok = ok and !(freq[i] % length);
            if(!ok)
                break;
        }
        
        return ok;
    }
};